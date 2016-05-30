#include "AddSpecialCommodity.h"
//#include "SpriteTextureController.h"
#include "GameTextInfo.h"
const std::string ADD_SPECIAL_COMMODITY_CSB_PATH = "AddSpecialCommodity.csb";
namespace bubble_second {
    AddSpecialCommodity::AddSpecialCommodity()
    {
    }


    AddSpecialCommodity::~AddSpecialCommodity()
    {
    }
    bool AddSpecialCommodity::init()
    {
        if (!EnterGamePropsView::init(ADD_SPECIAL_COMMODITY_CSB_PATH))
        {
            return false;
        }
        this->setCostLabelStringWithKey(COMMODITY_ADD_SPECIAL_KEY);
        this->setName(ADD_SPECIAL_COMMODITY_NAME);
        return true;
    }
}