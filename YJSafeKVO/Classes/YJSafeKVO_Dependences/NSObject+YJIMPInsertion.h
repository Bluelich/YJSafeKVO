//
//  NSObject+YJIMPInsertion.h
//  YJKit
//
//  Created by huang-kun on 16/7/3.
//  Copyright © 2016年 huang-kun. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (YJIMPInsertion)

/*
 
 @interface Foo : NSObject
 
 - (void)hello;
 + (void)hello;
 
 @end
 
 
 Foo *foo = [Foo new];
 [foo performBlocksByInvokingSelector:@selector(hello) ... // it will change the default IMP of instance method -hello
 [Foo performBlocksByInvokingSelector:@selector(hello) ... // it will change the default IMP of class method +hello
 
 
 // To summerize:
 
 // .If the receiver is an instance, it will change the default IMP of method by the given selector which represents an intance method.
 // .If the receiver is a class, it will change the default IMP of method by the given selector which represents an class method.
 
 */

/// @brief Perform blocks before and after the instance method (given selector) gets called.
///
/// @discussion If the class does not own the method by given selector originally, it will go up the
///             chain and check its super's.
///
/// @param selector   The selector for receiver (which responds to) for locating target method. If the
///                   selector is not responded by receiver, it will not crash but does nothing.
/// @param before     The block of code which will be executed before the method implementation.
/// @param after      The block of code which will be executed after the method implementation.
///
- (void)performBlocksByInvokingSelector:(SEL)selector
                                 before:(nullable void(^)(id receiver))before
                                  after:(nullable void(^)(id receiver))after;


/// @brief Perform blocks before and after the class method (given selector) gets called.
///
/// @discussion If the class does not own the method by given selector originally, it will go up the
///             chain and check its super's.
///
/// @param selector   The selector for receiver (which responds to) for locating target method. If the
///                   selector is not responded by receiver, it will not crash but does nothing.
/// @param before     The block of code which will be executed before the method implementation.
/// @param after      The block of code which will be executed after the method implementation.
///
+ (void)performBlocksByInvokingSelector:(SEL)selector
                                 before:(nullable void(^)(id receiver))before
                                  after:(nullable void(^)(id receiver))after;


/// @brief Perform block before dealloc
///
- (void)performBlockBeforeDeallocating:(void(^)(id receiver))block;


/// @brief Perform safe -isEqual:
/// @discussion If you have custom -isEqual: implementation, assuming the receiver and object parameter
///             have same class type. You would probably do properties comparison directly, and that may
///             not the safe way. e.g. Foo and bar are not generated by same class. Calling [foo isEqual:bar]
///             might crash if you implement -isEqual: for foo and compare foo's own property which bar
///             can not respond to that property.
///
- (void)performSafeEqualityComparison;

@end

NS_ASSUME_NONNULL_END