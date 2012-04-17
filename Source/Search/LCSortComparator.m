#import  "LCSortComparator.h"
#import  "LCScoreDocComparator.h"
#import  "LCScoreDoc.h"
#import  "LCSortField.h"
#import  "LCFieldCache.h"


@interface LCCacheScoreDocComparator: NSObject <LCScoreDocComparator>
{
	NSDictionary *cache;
}
- (void) setCache: (NSDictionary *) cache;
@end

@implementation LCCacheScoreDocComparator

- (void) dealloc
{
  cache=nil;;
}

- (void) setCache: (NSDictionary *) c
{
	cache = c;
}

- (NSComparisonResult) compare: (LCScoreDoc *) i to: (LCScoreDoc *) j
{
	id iValue = [cache objectForKey: [NSNumber numberWithInt: [i document]]];
	id jValue = [cache objectForKey: [NSNumber numberWithInt: [j document]]];
	return [(NSNumber *)iValue compare: jValue];
}

- (id) sortValue: (LCScoreDoc *) doc
{
	return [cache objectForKey: [NSNumber numberWithInt: [doc document]]];
}

- (int) sortType
{
	return LCSortField_CUSTOM;
}

@end

@implementation LCSortComparator
- (id) newComparator: (LCIndexReader *) reader
									  field: (NSString *) fieldname
{
	NSDictionary *cachedValues = [[LCFieldCache defaultCache] custom: reader field: fieldname sortComparator: self]; 
	LCCacheScoreDocComparator *comparator;
	comparator = [[LCCacheScoreDocComparator alloc] init];
	[comparator setCache: cachedValues];
	return comparator;
}

- (id) comparable: (NSString *) termtext
{
	return nil;
}

@end
