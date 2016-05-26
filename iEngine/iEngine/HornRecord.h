//
//  HornRecord.h
//  iEngine
//
//  Created by Isuru Kusumal Rajapakse on 5/27/16.
//  Copyright © 2016 Isuru Kusumal Rajapakse. All rights reserved.
//

#pragma once
#include "CompoundPredicate.h"

struct HornRecord
{
    Predicate* fPredicate;
    int fCount;
};
