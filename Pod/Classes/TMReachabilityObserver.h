/*
 Copyright (c) 2011, Tony Million.
 All rights reserved.
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
 
 1. Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.
 
 2. Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 POSSIBILITY OF SUCH DAMAGE.
 */

#import <Foundation/Foundation.h>
#import <SystemConfiguration/SystemConfiguration.h>

typedef NS_ENUM(NSInteger, TMReachableStatus) {
    TMReachableStatusNoneEnable = 1 << 0,
    TMReachableStatusWiFiEnable = 1 << 1,

    TMReachableStatus2GEnable = 1 << 8,
    TMReachableStatus3GEnable = 1 << 9,
    TMReachableStatus4GEnable = 1 << 10,
    TMReachableStatusWWANEnable = TMReachableStatus2GEnable | TMReachableStatus3GEnable | TMReachableStatus4GEnable,
};

@class TMReachabilityObserver;

typedef void (^TMNetworkReachable)(TMReachabilityObserver *reachability);
typedef void (^TMNetworkUnreachable)(TMReachabilityObserver *reachability);
typedef void (^TMNetworkReachability)(TMReachabilityObserver *reachability, SCNetworkConnectionFlags flags);

@interface TMReachabilityObserver : NSObject

@property (nonatomic, copy) TMNetworkReachable reachableBlock;
@property (nonatomic, copy) TMNetworkUnreachable unreachableBlock;
@property (nonatomic, copy) TMNetworkReachability reachabilityBlock;

@property (nonatomic, assign) BOOL reachableOnWWAN;


+ (instancetype)reachabilityWithHostname:(NSString *)hostname;
// This is identical to the function above, but is here to maintain
//compatibility with Apples original code. (see .m)
+ (instancetype)reachabilityWithHostName:(NSString *)hostname;
+ (instancetype)reachabilityForInternetConnection;
+ (instancetype)reachabilityWithAddress:(void *)hostAddress;
+ (instancetype)reachabilityForLocalWiFi;

- (instancetype)initWithReachabilityRef:(SCNetworkReachabilityRef)ref;

- (BOOL)startNotifier;
- (void)stopNotifier;

- (BOOL)isReachable;
- (BOOL)isReachableViaWWAN;
- (BOOL)isReachableViaWiFi;

// WWAN may be available, but not active until a connection has been established.
// WiFi may require a connection for VPN on Demand.
- (BOOL)isConnectionRequired;  // Identical DDG variant.
- (BOOL)connectionRequired;  // Apple's routine.
// Dynamic, on demand connection?
- (BOOL)isConnectionOnDemand;
// Is user intervention required?
- (BOOL)isInterventionRequired;

- (TMReachableStatus)currentReachabilityStatus;
- (SCNetworkReachabilityFlags)reachabilityFlags;
- (NSString *)currentReachabilityString;
- (NSString *)currentReachabilityFlags;

@end
