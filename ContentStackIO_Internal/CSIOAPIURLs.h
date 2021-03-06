//
//  CSIOAPIURLs.h
//  Contentstack
//
//  Created by Reefaq on 13/07/15.
//  Copyright (c) 2015 Built.io. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CSIOAPIURLs : NSObject

// BuiltQuery
//===========================================================================================
+(NSString *)fetchContentTypeEntriesQueryURLWithUID:(NSString *)contentTypeUID withVersion:(NSString*)version;

//stack
+(NSString *)fetchSchemaWithVersion:(NSString*)version;

//Entry
+ (NSString *)fetchEntryURLWithContentTypeUID:(NSString *)contentTypeUID entryUID:(NSString*)entryUID withVersion:(NSString*)version;

+ (NSString *)fetchContentTypeSchemaQueryURLWithVersion:(NSString *)version;

//Asset
+ (NSString *)fetchAssetWithUID:(NSString*)assetUID withVersion:(NSString*)version;

//AssetLibrary
+ (NSString *)fetchAssetLibraryWithVersion:(NSString*)version;

@end

