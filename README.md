# FLReachability

网络状态监听库

## Requirements

iOS 8.0

## Installation

FLReachability is available through [CocoaPods](http://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
source 'http://git.felink.com:3000/felink-iOS/FLSpecs'
pod "FLReachability", '~> 1.0.0'
```

## Usage

``` Objective-C
// 引用头文件
#import <FLReachability/FLReachability.h>

// 初始化
[FLReachabilityHelper checkReachability];

// 获取网络状态：
NSLog(@"%@", FLReachabilityHelper.isReachable ? @"网络正常" : @"网络异常");
NSLog(@"%@", FLReachabilityHelper.isWiFiReachable ? @"Wifi 联网" : @"非 Wifi 联网");
NSLog(@"%@", FLReachabilityHelper.isWWANReachable ? @"蜂窝联网" : @"非蜂窝联网");
NSLog(@"%@", @(FLReachabilityHelper.currentStatus));

// 监听网络状态变化
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onNetworkChange:) name:FLReachabilityChangedNotification object:nil];
```

## Author

chensiyi, chensiyi@felink.com

## License

FLReachability is available under the MIT license. See the LICENSE file for more info.
