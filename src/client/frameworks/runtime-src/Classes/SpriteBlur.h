#ifndef _SPRITE_BLUR_H_
#define _SPRITE_BLUR_H_
#include "cocos2d.h"
class SpriteBlur : public cocos2d::Sprite
{
public:
    SpriteBlur();
    ~SpriteBlur();
    static SpriteBlur* create(cocos2d::Sprite* pSprite, const float fRadius = 1.0f, const float fSampleNum = 1.0f);
    bool initWithTexture(cocos2d::Texture2D* pTexture, const cocos2d::Rect&  rRect);
    void initGLProgram();

    void setBlurRadius(float fRadius);
    void setBlurSampleNum(float fSampleNum);

protected:
    float fBlurRadius_;
    float fBlurSampleNum_;
};

#endif //_SPRITE_BLUR_H_


