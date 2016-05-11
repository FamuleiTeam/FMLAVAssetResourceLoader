//
//  FMLAVAssetResourceLoader.h
//  MQMediaPlayer
//
//  Created by famulei on 5/9/16.
//  Copyright © 2016 Damien. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>


#define kFMLMediaFolder @"com.famulei.media.cache"


@interface FMLAVAssetResourceLoader : NSObject<AVAssetResourceLoaderDelegate, NSURLSessionDataDelegate>

/**
 设置要加载的URL地址
 
 @param originURL     原始的URL的地址
 @param pathExtension 文件格式
 */
- (void)setOriginURL:(NSURL *)originURL pathExtension:(NSString *)pathExtension;
/**
 替换请求的协议，AVPlayer只有在请求协议不能被解析的时候才会调用回调。所以需要先替换URL的协议
 
 @param url 原始的URL
 
 @return 替换之后的URL
 */
- (NSURL *)schemeVideoURL:(NSURL *)url;

/**
 重置状态
 */
- (void)restoreState;

/**
 获取缓存的文件，如果返回nil，代表没有缓存。
 
 @param key           缓存的key，这里一般是URL的地址
 @param pathExtension 文件的格式
 
 @return 返回缓存的路径。
 */
+ (NSString *)filePathForKey:(NSString *)key pathExtension:(NSString *)pathExtension;

/**
 清楚在硬盘的缓存
 */
+ (void)clearCache;


@end
