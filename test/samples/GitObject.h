//
//  GITObject.h
//  Git.framework
//
//  Created by Geoff Garside on 08/12/2009.
//  Copyright 2009 Geoff Garside. All rights reserved.
//

#import <Foundation/Foundation.h>

// Some other File Comment
// That I wrote here

typedef enum {
    GITObjectTypeUnknown = 0,
    GITObjectTypeCommit  = 1,
    GITObjectTypeTree    = 2,
    GITObjectTypeBlob    = 3,
    GITObjectTypeTag     = 4,
} GITObjectType;

@class GITObjectHash, GITRepo;

/**
 * Protocol for children of the GITObject class to implement.
 *
 * The protocol defines the methods which a GITObject child should implement
 * but which are not really appropriate to be defined within the GITObject
 * class itself.
 */
@protocol GITObject <NSObject>

/**
 * Returns the string type of the receiving GITObject child class.
 *
 * @return string type of the receiver
 * @see type
 * @task Type translations
 */
+ (NSString *)typeName;

/**
 * Returns the GITObjectType of the receiving GITObject child class.
 *
 * @return GITObjectType of the receiver
 * @sa typeName
 * @task Type translations
 */
+ (GITObjectType)type;

/**
 * Creates and returns an instance of the receiving class.
 *
 * The \a data contains the representation of the object to create, the \a repo
 * specifies the parent repository and where any additional objects associated
 * with the object may be loaded from.
 *
 * @1 Data containing the representation of the object to create
 * @2 The SHA1 hash of the receiver
 * @3 Repository parent of the object
 * @4 NSError describing any errors which occurred
 * @return Instance of the receiving class
 * @task Initialisers
 */
- (id)initFromData: (NSData *)data sha1: (GITObjectHash *)objectHash repo: (GITRepo *)repo error: (NSError **)error;

@end

/**
 * GITObject is an \e abstract class which provides fields and methods common to all
 * inheriting classses.
 *
 * The GITObject
 */
@interface GITObject : NSObject {
    /**
     * type of the object
     */
    GITObjectType  type;
    
    /**
     * SHA1 hash of the object
     */
    GITObjectHash *sha1;
    
    /**
     * The repository the object is part of
     */
    GITRepo *repo;
    
    /**
     * The size of the object
     */
    NSUInteger size;
}

@property (assign) GITObjectType  type;
@property (retain) GITObjectHash *sha1;
@property (retain) GITRepo *repo;
@property (assign) NSUInteger size;

/**
 * Returns the string equivalent of the \a type.
 *
 * @1 GITObjectType to convert to a string
 * @return String equivalent to the \a type
 * @see objectTypeForString:
 * @task Object Type to String Conversion
 */
+ (NSString *)stringForObjectType: (GITObjectType)type;

/**
 * Returns the GITObjectType equivalent of the \a type.
 *
 * @1 type String to convert to a GITObjectType value
 * @return GITObjectType equivalent to the \a type
 * @see stringForObjectType:
 * @task Object Type to String Conversion
 */
+ (GITObjectType)objectTypeForString: (NSString *)type;

/**
 * Creates and returns an object of the \a type specified composed of the \a data within the \a repo.
 *
 * In the event that an error occurrs while creating the object the \a error will describe the nature of the
 * error which occurred.
 *
 * This method is essentially a dispatcher, based on the \a type provided the default initializer for the
 * correct GITObject subtype will be called to create the correct representation and return the new object.
 *
 * @1 The type of the object to create
 * @2 The data composing the object
 * @3 The SHA1 hash of the object
 * @4 The repository the object is a member of
 * @5 NSError describing the error which occurred
 * @return object from the \a type from the \a data
 * @task Initialisers
 */
+ (id)objectOfType: (GITObjectType)type withData: (NSData *)data sha1: (GITObjectHash *)objectHash repo: (GITRepo *)repo error: (NSError **)error;

/**
 * Returns a GITObject initialised with the \a type, \a objectHash and \a repo.
 *
 * This method is intended to be used by the git object type classes initialiser methods [super init...] call, the
 * purpose is to initialise the fields common to all of the GITObject children.
 *
 * @1 Type of object
 * @2 Hash of the object
 * @3 Repository the object is a member of
 * @return object initialised with the provided values
 */
- (id)initWithType: (GITObjectType)type sha1: (GITObjectHash *)objectHash repo: (GITRepo *)repo;

@end
