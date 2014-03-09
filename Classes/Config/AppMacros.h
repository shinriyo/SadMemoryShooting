//
//  AppMacros.h
//  SadMemoryonYourWhiteCampus
//
//  Created by KubokawaTakeshi on 2014/02/23.
//
//

#ifndef __SadMemoryonYourWhiteCampus__AppMacros__
#define __SadMemoryonYourWhiteCampus__AppMacros__

#include <iostream>
#include "GameConfig.h"

typedef struct tagResource
{
    CCSize size;
    char directory[100];

} Resource;

/* iOS */
static Resource smallResource   = { CCSizeMake(512, 384), "resources-small"  };
static Resource largeResource   = { CCSizeMake(1024, 768), "resources-large" };
static Resource xlargeResource  = { CCSizeMake(2048,1536), "resouces-xlarge" };
/* Android */


/* ------- */
static CCSize designResolutionSize = CCSizeMake(1024, 577);



#endif /* defined(__SadMemoryonYourWhiteCampus__AppMacros__) */
