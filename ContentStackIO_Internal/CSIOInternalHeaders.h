//
//  CSIOInternalHeaders.h
//  contentstack
//
//  Created by Reefaq on 15/07/15.
//  Copyright (c) 2015 Built.io. All rights reserved.
//

#import "CSIOCoreNetworkingProtocol.h"
#import "Contentstack.h"
#import "Stack.h"
#import "Query.h"
#import "ContentType.h"
#import "Entry.h"
#import "Asset.h"
#import "QueryResult.h"
#import "ISO8601DateFormatter.h"
#import "Common.h"
#import "CSIOConstants.h"
#import "Config.h"
#import "AssetLibrary.h"
#import "Group.h"


//MARK: Extensions -

@interface Stack ()
@property (nonatomic, copy) NSString *hostURL;
@property (nonatomic, copy) NSString *version;
@property (nonatomic, assign) BOOL ssl;
@property (nonatomic, strong) NSMutableDictionary *stackHeaders;
@property (nonatomic, strong) NSObject<CSIOCoreNetworkingProtocol> *network;
@property (nonatomic, strong) ISO8601DateFormatter *commonDateFormatter;
- (instancetype)initWithAPIKey:(NSString*)apiKey andAccessToken:(NSString *)accessToken andEnvironment:(NSString*)environment andConfig:(Config *)sConfig;
@end

@interface Contentstack()
+ (Contentstack *)sharedInstance;
@end


@interface Query ()
@property (nonatomic, assign) BOOL shouldFetchFromNetwork;
@property (nonatomic, strong) ContentType *contentType;
- (instancetype)initWithContentType:(ContentType *)contentType;
@property (nonatomic, strong) NSMutableDictionary *queryDictionary;

@end

@interface QueryResult ()
- (instancetype)initWithContentType:(ContentType *)contentType objectDictionary:(NSDictionary*)dictionary;
@property (nonatomic, strong) ContentType *contentType;
@end

@interface ContentType ()
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSMutableDictionary *headers;

-(instancetype)initWithStack:(Stack *)stack withName:(NSString*)contentTypeName;
-(Entry *)entry;
-(Stack *)stack;
@end

@interface Entry ()
@property (nonatomic, assign, getter=isDeleted) BOOL deleted;
@property (nonatomic, strong) ContentType *contentType;
@property (nonatomic, strong) NSMutableDictionary *postParamDictionary;
- (instancetype)initWithContentType:(ContentType *)contentType;
- (instancetype)initWithContentType:(ContentType *)contentType withEntryUID:(NSString*)uid;

@end
@interface Asset ()
- (instancetype)initWithStack:(Stack *)stack;
- (instancetype)initWithStack:(Stack *)stack withAssetUID:(NSString*)assetUID;
@property (nonatomic, strong) NSMutableDictionary *postParamDictionary;

@end

@interface AssetLibrary ()
- (instancetype)initWithStack:(Stack *)stack;
@property (nonatomic, strong) NSMutableDictionary *postParamDictionary;
@end

@interface Group ()
- (void)configureWithDictionary:(NSDictionary*)dictionary;
- (instancetype)initWithStack:(Stack *)stack;
- (instancetype)initWithStack:(Stack *)stack andField:(NSString*)field;

@end
