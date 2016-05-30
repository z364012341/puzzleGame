#include "PuzzleStageDataManager.h"
const std::string PUZZLE_STAGE_DATA_PATH = "res/puzzleStageData.plist";
namespace bubble_second {
    void PuzzleStageDataManager::loadPuzzleStageData()
    {
        auto file_utils = cocos2d::FileUtils::getInstance();
        //std::string path = this->getStageDataPath();
        if (file_utils->isFileExist(PUZZLE_STAGE_DATA_PATH))
        {
            puzzle_stage_data_ = file_utils->getValueMapFromFile(PUZZLE_STAGE_DATA_PATH);
        } 
    }
    int PuzzleStageDataManager::getGameTimeWithkey(const std::string & key)
    {
        if (puzzle_stage_data_.find(key) == puzzle_stage_data_.end())
        {
            assert(false);
            return -1;
        }
        return puzzle_stage_data_[key].asInt();
    }
    PuzzleStageDataManager::PuzzleStageDataManager()
    {
    }


    PuzzleStageDataManager::~PuzzleStageDataManager()
    {
    }
}