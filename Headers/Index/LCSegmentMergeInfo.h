#ifndef __LUCENE_INDEX_SEGMENT_MERGE_INFO__
#define __LUCENE_INDEX_SEGMENT_MERGE_INFO__

#import  <Foundation/Foundation.h>
#import  "LCTermPositions.h"
#import  "LCPriorityQueue.h"
#import  "LCIndexReader.h"

@interface LCSegmentMergeInfo: NSObject <LCComparable>
{
	LCTerm *term;
	int base;
	LCTermEnumerator *termEnum;
	LCIndexReader *reader;
	id <LCTermPositions> postings;
	NSMutableArray *docMap; // maps around deleted docs
}

- (id) initWithBase: (int) b termEnumerator: (LCTermEnumerator *) te 
			 reader: (LCIndexReader *) r;
- (LCTerm *) term;
- (LCTermEnumerator *) termEnumerator;
- (int) base;
- (BOOL) hasNextTerm;
- (void) close;
- (NSArray *) docMap;
- (id <LCTermPositions>) postings;
@end
#endif /* __LUCENE_INDEX_SEGMENT_MERGE_INFO__ */
