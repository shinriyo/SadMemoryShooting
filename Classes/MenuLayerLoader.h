//
//  MenuLayerLoader.h
//  SadMemoryonYourWhiteCampus
//
//  Created by KubokawaTakeshi on 2014/02/22.
//
//

#ifndef __SadMemoryonYourWhiteCampus__MenuLayerLoader__
#define __SadMemoryonYourWhiteCampus__MenuLayerLoader__

#include <iostream>
#include "GameConfig.h"
#include "MenuLayer.h"

class MenuLayerLoader : public extension::CCLayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(MenuLayerLoader, loader);
    
private:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(MenuLayer);
};

#endif /* defined(__SadMemoryonYourWhiteCampus__MenuLayerLoader__) */
