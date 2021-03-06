#ifndef __LUCENE_SEARCH_SCORE_DOC__
#define __LUCENE_SEARCH_SCORE_DOC__

#import  <Foundation/Foundation.h>
#import  "LCPriorityQueue.h"

@interface LCScoreDoc: NSObject <LCComparable>
{
	float score;
	int doc;
}

- (id) initWithDocument: (int) doc score: (float) score;
- (float) score;
- (void) setScore: (float) score;
- (int) document;

@end

#endif /* __LUCENE_SEARCH_SCORE_DOC__ */
