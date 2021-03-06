/*
 * cocos2d for iPhone: http://www.cocos2d-iphone.org
 *
 * Copyright (c) 2008-2010 Ricardo Quesada
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */



#import <UIKit/UIKit.h>

#import "CCAction.h"

/** Instant actions are immediate actions. They don't have a duration like
 the CCIntervalAction actions.
*/ 
@interface CCInstantAction : CCFiniteTimeAction <NSCopying>
{}
@end

/** Show the node
 */
 @interface CCShow : CCInstantAction
{
}
@end

/** Hide the node
 */
@interface CCHide : CCInstantAction
{
}
@end

/** Toggles the visibility of a node
 */
@interface CCToggleVisibility : CCInstantAction
{
}
@end

/** Flips the sprite horizontally
 @since v0.99.0
 */
@interface CCFlipX : CCInstantAction
{
	BOOL	flipX;
}
+(id) actionWithFlipX:(BOOL)x;
-(id) initWithFlipX:(BOOL)x;
@end

/** Flips the sprite vertically
 @since v0.99.0
 */
@interface CCFlipY : CCInstantAction
{
	BOOL	flipY;
}
+(id) actionWithFlipY:(BOOL)y;
-(id) initWithFlipY:(BOOL)y;
@end

/** Places the node in a certain position
 */
@interface CCPlace : CCInstantAction <NSCopying>
{
	CGPoint position;
}
/** creates a Place action with a position */
+(id) actionWithPosition: (CGPoint) pos;
/** Initializes a Place action with a position */
-(id) initWithPosition: (CGPoint) pos;
@end

/** Calls a 'callback'
 */
@interface CCCallFunc : CCInstantAction <NSCopying>
{
	id targetCallback;
	SEL selector;
}
/** creates the action with the callback */
+(id) actionWithTarget: (id) t selector:(SEL) s;
/** initializes the action with the callback */
-(id) initWithTarget: (id) t selector:(SEL) s;
/** exeuctes the callback */
-(void) execute;
@end

/** Calls a 'callback' with the node as the first argument
 N means Node
 */
@interface CCCallFuncN : CCCallFunc
{
}
@end


typedef void (*CC_CALLBACK_ND)(id, SEL, id, void *);
/** Calls a 'callback' with the node as the first argument and the 2nd argument is data
 * ND means: Node and Data. Data is void *, so it could be anything.
 */
@interface CCCallFuncND : CCCallFuncN
{
	void			*data;
	CC_CALLBACK_ND	callbackMethod_;
}

/** Invocation object that has the target#selector and the parameters */
@property (nonatomic,readwrite) CC_CALLBACK_ND callbackMethod;

/** creates the action with the callback and the data to pass as an argument */
+(id) actionWithTarget: (id) t selector:(SEL) s data:(void*)d;
/** initializes the action with the callback and the data to pass as an argument */
-(id) initWithTarget:(id) t selector:(SEL) s data:(void*) d;
@end

#pragma mark Blocks Support

#if NS_BLOCKS_AVAILABLE

/** Executes a callback using a block
 */
@interface CCCallBlock : CCInstantAction<NSCopying>
{
	void (^block_)();
}

/** creates the action with the specified block, to be used as a callback */
+(id) actionWithBlock:(void(^)())block;

/** initialized the action with the specified block, to be used as a callback */
-(id) initWithBlock:(void(^)())block;

/** executes the callback */
-(void) execute;
@end

@class CCNode;

/** Executes a callback using a block with a single CCNode parameter
 */
@interface CCCallBlockN : CCInstantAction<NSCopying>
{
	void (^block_)(CCNode *);
}

/** creates the action with the specified block, to be used as a callback */
+(id) actionWithBlock:(void(^)(CCNode *node))block;

/** initialized the action with the specified block, to be used as a callback */
-(id) initWithBlock:(void(^)(CCNode *node))block;

/** executes the callback */
-(void) execute;
@end

#endif
