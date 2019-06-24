//
//  NetworkStatusMgr.m
//  PandaHome_iPhone
//
//  Created by humin on 12-3-20.
//  Copyright 2012 nd.com.cn. All rights reserved.
//

#import "TMReachabilityHelper.h"
#import "TMReachability.h"

//请求测试
#define kTestNetWorkHostName @"www.baidu.com"

@interface TMReachabilityHelper()

@property (nonatomic, strong) TMReachabilityObserver *hostReach;

@end

@implementation TMReachabilityHelper

@synthesize hostReach = _hostReach;

+ (void)load
{
    [TMReachabilityHelper checkReachability];
}

+ (instancetype)sharedInstance
{
    static TMReachabilityHelper *instance = nil;
    static dispatch_once_t predicate;
    dispatch_once(&predicate, ^{
        instance = [[self alloc] init];
    });
    return instance;
}

+ (BOOL)isReachable
{
    return [TMReachabilityHelper sharedInstance].isReachable;
}

+ (BOOL)isWWANReachable
{
    return [TMReachabilityHelper sharedInstance].isWWANReachable;
}

+ (BOOL)isWiFiReachable
{
    return [TMReachabilityHelper sharedInstance].isWiFiReachable;
}

+ (TMReachableStatus)currentStatus
{
    return [TMReachabilityHelper sharedInstance].currentStatus;
}

+ (void)checkReachability
{
    [[TMReachabilityHelper sharedInstance] checkReachability];
}

//获取网络状态
- (BOOL)isReachable
{
    return self.hostReach.isReachable;
}


- (BOOL)isWWANReachable
{
    return self.hostReach.isReachableViaWWAN;
}

- (BOOL)isWiFiReachable
{
    return self.hostReach.isReachableViaWiFi;
}

//获取联网方式
- (TMReachableStatus)currentStatus
{
    return [self.hostReach currentReachabilityStatus];
}

- (void)checkReachability
{
    //host
    self.hostReach = [TMReachabilityObserver reachabilityWithHostName:kTestNetWorkHostName];
    [self.hostReach startNotifier];
}

@end
