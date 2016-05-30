#ifndef __ZCG_CONFIG_DATA_DICT_H__
#define __ZCG_CONFIG_DATA_DICT_H__
#include <map>
#include <string>
const int KEY_FRAME_WIDTH = 1001;
const int KEY_FRAME_HEIGHT = 1002;
const int KEY_OPEN_CMD_SHOW = 1003;
const int KEY_GAME_VERSION = 1004;
const int KEY_STAGE_VERSION = 1005;
class ZCGConfigDataDict
{
public:
	static ZCGConfigDataDict* getInstance();
    const std::string getStringData(int key) const;
	const int getIntData(int key) const;
protected:
	ZCGConfigDataDict(void);
	~ZCGConfigDataDict(void);
    void loadInfos();
	//static ZCGConfigDataDict* m_dict;
    std::map<int, std::string> m_datasMap;
};
#endif 

