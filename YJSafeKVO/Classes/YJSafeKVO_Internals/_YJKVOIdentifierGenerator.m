//
//  _YJKVOIdentifierGenerator.m
//  YJKit
//
//  Created by huang-kun on 16/7/9.
//  Copyright © 2016年 huang-kun. All rights reserved.
//

#import "_YJKVOIdentifierGenerator.h"

@implementation _YJKVOIdentifierGenerator

+ (instancetype)sharedGenerator {
    static _YJKVOIdentifierGenerator *sharedGenerator;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedGenerator = [_YJKVOIdentifierGenerator new];
    });
    return sharedGenerator;
}

- (NSString *)pipeIdentifierForTarget:(__kindof NSObject *)target
                           subscriber:(__kindof NSObject *)subscriber
                        targetKeyPath:(NSString *)targetKeyPath
                    subscriberKeyPath:(NSString *)subscriberKeyPath {
    
    return [NSString stringWithFormat:@"%@|%@",
            [self keyValueCodingIdentifierForObject:target keyPath:targetKeyPath],
            [self keyValueCodingIdentifierForObject:subscriber keyPath:subscriberKeyPath]];
}

- (NSString *)keyValueCodingIdentifierForObject:(__kindof NSObject *)object
                                        keyPath:(NSString *)keyPath {
    return [NSString stringWithFormat:@"%@<%p>.%@", NSStringFromClass([object class]), object, keyPath];
}

@end
