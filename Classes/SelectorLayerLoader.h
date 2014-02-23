//
//  SelectorLayerLoader.h
//  SadMemoryonYourWhiteCampus
//
//  Created by KubokawaTakeshi on 2014/02/23.
//
//

#ifndef __SadMemoryonYourWhiteCampus__SelectorLayerLoader__
#define __SadMemoryonYourWhiteCampus__SelectorLayerLoader__

#include <iostream>
#include "GameManager.h"
#include "SelectStageLayer.h"

class SelectStageLayerLoader : public extension::CCLayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(SelectStageLayerLoader, loader);
    
public:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(SelectStageLayer);
    
};

#endif /* defined(__SadMemoryonYourWhiteCampus__SelectorLayerLoader__) */
