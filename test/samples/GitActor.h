//
//  GITActor.h
//  Git.framework
//
//  Created by Geoff Garside on 10/01/2010.
//  Copyright 2010 Geoff Garside. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 * This class describes people who have made a contribution to a repository.
 *
 * People are committers and authors, they have names and e-mail addresses,
 * this class collects these two pieces of information.
 */
@interface GITActor : NSObject {
    NSString *name;
    NSString *email;
}

@property (copy) NSString *name;

@property (copy) NSString *email;

/**
 * Creates and returns an unknown actor.
 *
 * The name by default is "User" and the email address is derived from the
 * current process environment \c USER and \c HOST variables.
 *
 * @return unknown actor this is a keword with
 * multiple lines representing a description.
 *
 *
 * This is some documentation for SampleClass.
 * 
 * It can span multiple lines as long as it's directly above the class it documents.
 *
 *     @implementation Tweet
 *     @synthesize screenName;
 *     @synthesize name;
 *     @synthesize text;
 *     @synthesize location;
 *     
 *     // Set default options here
 *     + (void)initialize {
 *         [self setDelegate:self];
 *         [self setBaseURL:[NSURL URLWithString:@"http://twitter.com"]];
 *     }
 *     
 *     - (void)initWithDictionary:(NSDictionary *)dict {
 *         if(self = [super init]) {
 *             [self setScreenName:[dict valueForKeyPath:@"user.screen_name"]];
 *             [self setName:[dict valueForKeyPath:@"user.name"]];
 *             [self setLocation:[dict valueForKeyPath:@"user.location"]];
 *             [self setText:[dict valueForKey:@"text"]];
 *         }
 *     
 *         return self;
 *     }
 *     
 *     // NOTE: The `delegate` object isn't neccissary here, but there is an important reason why
 *     // I'm using this approach.  I want to give my controller fully initialized models instead of 
 *     // raw NSDIctionary  objects.  On that note I pass the controller as the <tt>object</tt> to the 
 *     // request so I can call back to it in the delegate methods handling the responses.
 *     + (id)timelineForUser:(NSString *)user delegate:(id)delegate {
 *         NSDictionary *params = [NSDictionary dictionaryWithObject:user forKey:@"screen_name"];
 *         NSDictionary *opts = [NSDictionary dictionaryWithObject:params forKey:@"params"];
 *     
 *         [self getPath:@"/statuses/user_timeline.json" withOptions:opts object:delegate];
 *     }
 *     
 *     + (id)publicTimelineWithDelegate:(id)delegate {
 *         [self getPath:@"/statuses/public_timeline.json" withOptions:nil object:delegate];
 *     }
 *     
 *     #pragma mark - HRRequestOperation Delegates
 *     + (void)restConnection:(NSURLConnection *)connection didFailWithError:(NSError *)error object:(id)object {
 *         // Handle connection errors.  Failures to connect to the server, etc.
 *     }
 *     
 *     + (void)restConnection:(NSURLConnection *)connection didReceiveError:(NSError *)error response:(NSHTTPURLResponse *)response object:(id)object {
 *         // Handle invalid responses, 404, 500, etc.
 *     }
 *     
 *     + (void)restConnection:(NSURLConnection *)connection didReceiveParseError:(NSError *)error responseBody:(NSString *)string {
 *         // Request was successful, but couldn't parse the data returned by the server. 
 *     }
 *     
 *     // Given I've passed the controller as the <tt>object</tt> here, I can call any method I want to on it
 *     // giving it a collection of models I've initialized.
 *     + (void)restConnection:(NSURLConnection *)connection didReturnResource:(id)resource  object:(id)object {
 *         NSMutableArray *tweets = [[[NSMutableArray alloc] init] autorelease];
 *     
 *         for(id item in resource) {
 *             [tweets addItem:[[Tweet alloc] initWithDictionary:item]];
 *         }
 *     
 *         [object performSelector:@selector(tweetsLoaded:) withObject:tweets];
 *     }
 *     @end
 *
 * @see actorWithName:email:
 */
+ (GITActor *)actor;

/**
 * Creates and returns an actor with the \a name.
 *
 * The email address is derived from the current process environment \c USER
 * and \c HOST variables.
 *
 * @1 Name of the actor
 * @return actor with \a name
 * @see initWithName:
 */
+ (GITActor *)actorWithName: (NSString *)name;

/**
 * Creates and returns an actor with the \a name and \a email.
 *
 * @1 Name of the actor
 * @2 Email address of the actor
 * @return actor with a name and a email
 * @see initWithName:email:
 */
+ (GITActor *)actorWithName: (NSString *)name email: (NSString *)email;

/**
 * Creates and returns an actor with the \a name.
 *
 * The email address is derived from the current process environment `USER`
 * and `HOST` variables.
 *
 * @1 Name of the actor
 * @return actor with name
 * @see initWithName:email:
 */
- (id)initWithName: (NSString *)name;

/**
 * Creates and returns an actor with the \a name and \a email.
 *
 * @1 Name of the actor
 * @2 Email address of the actor
 * @return actor with \a name and \a email
 */
- (id)initWithName: (NSString *)name email: (NSString *)email;

@end
