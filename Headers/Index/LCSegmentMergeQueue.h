#ifndef __LUCENE_INDEX_SEGMENT_MERGE_QUEUE__
#define __LUCENE_INDEX_SEGMENT_MERGE_QUEUE__

#import  "LCPriorityQueue.h"

@interface LCSegmentMergeQueue: LCPriorityQueue
- (void) close;
@end

#endif /* __LUCENE_INDEX_SEGMENT_MERGE_QUEUE__ */
