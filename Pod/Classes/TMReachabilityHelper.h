//
//  NetworkStatusMgr.h
//  PandaHome_iPhone
//
//  Created by humin on 12-3-20.
//  Copyright 2012 nd.com.cn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TMReachabilityObserver.h"

/**
 监听网络状态工具类
 */
@interface TMReachabilityHelper : NSObject

@property (class, nonatomic, assign, readonly) BOOL isReachable;  // 网络是否可达
@property (class, nonatomic, assign, readonly) BOOL isWWANReachable;  // 是否使用蜂窝数据联网
@property (class, nonatomic, assign, readonly) BOOL isWiFiReachable;  // 是否使用 wifi 联网
@property (class, nonatomic, assign, readonly) TMReachableStatus currentStatus;  // 联网状态

/**
 检查网络状态
 
 程序启动时会自动检测
 FLReachabilityChangedNotification 可用于监听网络状态变更
 */
+ (void)checkReachability;

@end
