//
//  OsmMapData+Straighten.h
//  Go Map!!
//
//  Created by Bryce Cogswell on 7/9/14.
//  Copyright (c) 2014 Bryce Cogswell. All rights reserved.
//



#import "OsmMapData.h"

@class OsmWay;

@interface OsmMapData (Straighten)

- (BOOL)straightenWay:(OsmWay *)way;
- (BOOL)reverseWay:(OsmWay *)way;
- (EditAction)canDisconnectWay:(OsmWay *)selectedWay atNode:(OsmNode *)node;
- (EditActionReturnWay)canSplitWay:(OsmWay *)selectedWay atNode:(OsmNode *)node;	// returns the new other half
- (EditAction)canJoinWay:(OsmWay *)selectedWay atNode:(OsmNode *)selectedNode;
- (BOOL)circularizeWay:(OsmWay *)way;
- (OsmBaseObject *)duplicateObject:(OsmBaseObject *)object;

-(OsmRelation *)updateTurnRestrictionRelation:(OsmRelation *)restriction viaNode:(OsmNode *)viaNode
									  fromWay:(OsmWay *)fromWay
								  fromWayNode:(OsmNode *)fromWayNode
										toWay:(OsmWay *)toWay
									toWayNode:(OsmNode *)toWayNode
										 turn:(NSString *)strTurn
									  newWays:(NSArray **)resultWays
									willSplit:(BOOL(^)(NSArray * splitWays))requiresSplitting;
@end
