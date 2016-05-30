//*******************************************************************************
//�ļ���         : <BubbleSecondConstant.h>
//�ļ�ʵ�ֹ���  : <������Ŀ�õ��ĳ���>
//����         : <�����.,.>
//�汾         : <1.0>
//-------------------------------------------------------------------------------
//�޸ļ�¼ :
//�� ��        �汾     �޸���              �޸�����
//2015/09/15   1.0     <�����>            <�����>
//*******************************************************************************
#ifndef _BUBBLE_SECOND_CONSTANT_H_
#define _BUBBLE_SECOND_CONSTANT_H_
#include "cocos2d.h"
//#include "StageData.h"
#define GETINSTANCE_FUNC(__TYPE__) \
    static __TYPE__* getInstance() \
    { \
        static __TYPE__ instance_; \
        return &instance_; \
    }// \
   // __TYPE__ & operator = (const __TYPE__ &) = delete;
#define SINGLE_BUBBLE_SCORE(_COMBO_)          (5*(_COMBO_)+5)                                  //����С��������÷�
#define BUBBLE_ELIMINATE_FORMULA(_NUM_,_COMBO_) ((_NUM_)*SINGLE_BUBBLE_SCORE(_COMBO_))             //�����÷ּ��㹫ʽ
#define RANDOM_DECIMALS(_MIN_, _MAX_) (cocos2d::random(_MIN_, _MAX_) + cocos2d::rand_0_1()) //����һ��һλ���С��
#define GAME_STAGE_NODE_CSB_FORMAT "StageNode%d.csb"
//��Դ·��
const std::string GAME_SCENE = "GameScene";
const std::string GAME_LAYER_CSB = "GameLayer.csb";
const std::string GAME_RIGHT_INFO_NAME = "right_UI_node";
const float GAME_RIGHT_STAGE_SPRITE_POS_X = -90.0f; //�ؿ�����ͼ��λ��
const std::string BUBBLE_NO_COLOR_PATH = ""; //��ɫ             
const std::string BUBBLE_YELLOW_PATH = "paopaohuang.PNG"; //��
const std::string BUBBLE_PURPLE_PATH = "paopaozi.PNG"; //��
const std::string BUBBLE_BLUE_PATH = "paopaolan.PNG"; //��
const std::string BUBBLE_RED_PATH = "paopaohong.PNG"; //��
const std::string BUBBLE_GREEN_PATH = "paopaolv.PNG"; //��
const std::string BUBBLE_ORANGE_PATH = "paopaocheng.PNG"; //��
const std::string BUBBLE_PINK_PATH = "paopaofen.PNG";//��
const std::string BUBBLE_LIGHTNING_PATH = "paopaoshandian.PNG"; //��������
const std::string BUBBLE_DARKCLOUD_PATH = "yinyun.png";      //��������
const std::string BUBBLE_BLACKHOLE_PATH = "heidong.png"; //�ڶ�����
const std::string BUBBLE_BOMB_BOMB_PATH = "huoqiu.png"; //ը������
const std::string BUBBLE_RAINBOW_SEAL_PATH = "kuangliubianxing.PNG"; //�ʺ��ӡ����
const std::string BUBBLE_MUTIPLE_SEAL_1_PATH = "paopaotouming.PNG"; //һ�ط�ӡ����
const std::string BUBBLE_MUTIPLE_SEAL_3_PATH = "paopaotoumingsanjiao.PNG"; //���ط�ӡ����
const std::string BUBBLE_MUTIPLE_SEAL_7_PATH = BUBBLE_RAINBOW_SEAL_PATH; //���ط�ӡ����
//const std::string POP_SCORE_CHARMAP_PATH = "popscore.png";   //�������������������õ�ͼƬ
const std::string TOP_UI_BACKGROUND_PATH = "uishang.PNG";   //�ϱ�ui�ı���
const std::string BOTTOM_UI_BACKGROUND_PATH = "uixia.PNG";    //�±�ui�ı���
const std::string GAME_PLAYING_MENU_NORMAL_PATH = "anniucaidan.PNG"; //��Ϸ�������½ǵĲ˵�ͼƬ��Դ
const std::string PROPS_ITEM_BACKGROUND_PATH = "kuangdaoju.png";  //����item�ı���
//const std::string GUNSIGHT_SWIRL_RED_PATH = "X-hong.png";  //����̨�ϵ������
//const std::string GUNSIGHT_SWIRL_PINK_PATH = "X-fen.png";  //����̨�ϵ������
//const std::string GUNSIGHT_SWIRL_PURPLE_PATH = "X-purple.png";  //����̨�ϵ�������
//const std::string GUNSIGHT_SWIRL_ORANGE_PATH = "X-cheng.png";  //����̨�ϵ������
//const std::string GUNSIGHT_SWIRL_BLUE_PATH = "X-lan.png";  //����̨�ϵ�������
//const std::string GUNSIGHT_SWIRL_YELLOW_PATH = "X-huang.png";  //����̨�ϵ������
//const std::string GUNSIGHT_SWIRL_GREEN_PATH = "X-lv.png";  //����̨�ϵ�������
const std::string RAINBOW_CHARACTOR_PATH = "be_sealed_charactor.png"; //�ʺ��ӡ���������
const std::string ADD_BUBBLE_NUMBLE_BUBBLE_PATH = "addThreeBubble.png"; //+3��������
const std::string GAME_NUMBLE_FONT_PATH = "fonts/typeface-export.fnt";

//��׼�ߵ�path
const std::string SIGHT_POINT_COLORFUL_PATH = "caisedian.png";  //��ɫ��
const std::string SIGHT_POINT_ORANGE_PATH = "chengdian.png";
const std::string SIGHT_POINT_PINK_PATH = "fendian.png";
const std::string SIGHT_POINT_RED_PATH = "hongdian.png";
const std::string SIGHT_POINT_YELLOW_PATH = "huangdian.png";
const std::string SIGHT_POINT_BLUE_PATH = "landian.png";
const std::string SIGHT_POINT_GREEN_PATH = "lvdian.png";
const std::string SIGHT_POINT_PURPLE_PATH = "zidian.png";
////��ɫ
const std::string ROLE_GENJYO_SANZO_NAME = "GenJyo_Sanzo";  //�������i
//const std::string ROLE_GENJYO_SANZO_PATH = "tangseng.png";  //�������i
//const std::string ROLE_CHO_GONO_NAME = "Cho_Gono"; //�˽�
//const std::string ROLE_CHO_GONO_PATH = "bajie.png";  //�˽�Ĺ�ȥ�ܱ��ҡ����������˺ܲ��ҵ����ڲ�ͬ�Ĺ¶�Ժ�ﳤ��Ľ�㡣ԭ�������ڴ��������ƽ����������ȴ������ħ��ץ���ˡ���Ϊ�˾Ȼ�ૣ�ɱ���˰���ħ�����ϴ��СС��������ȫ��������һ����ʣ��Ȼ���������Ϊ�Ѿ����а���ħ���Ĺ����������ǰ��ɱ�ˡ�������������һǧֻ���ֵ�Ѫ���Լ�Ҳ��������֡������������������ܴ̼�����������·�ߣ����򾻾�����������ڴ����������ذ����£������ﱻ���������⣬�������˽䡱����ʼ�µ����
//const std::string ROLE_SON_GOKU_NAME = "Son_Goku";  //�����
//const std::string ROLE_SON_GOKU_PATH = "wukong.png";  //�����
////����
//const std::string PET_SHAKURYU_NAME = "Shakuryu";  //����
//const std::string PET_SHAKURYU_PATH = "baima.png";  //����
//const std::string PET_MONKEY_NAME = "monkey";  //����
//const std::string PET_MONKEY_PATH = "xiaohou.png";  //����
//����item
const std::string PROPS_NUMBLE_ENABLED_PATH = "anniutianjia.PNG"; //���Ͻǵİ�++ť
const std::string PROPS_NUMBLE_DISABLED_PATH = "anniushuliang.PNG";
const float PROPS_BUTTON_SPRITE_SCALE = 0.8f;
const float PROPS_BUTTON_SELECT_SCALE = 1.2f;
const int PROPS_BUTTON_ZORDER = 1;
//����
const std::string PROPS_COLOR_BOMB_NAME = "props_color_bomb"; //����
const std::string PROPS_COLOR_BOMB_PATH = "daojucaiqiu.PNG";
const std::string PROPS_BOMB_BOMB_NAME = "props_bomb_bomb"; //ը��
const std::string PROPS_BOMB_BOMB_PATH = "daojuzhadan.PNG";
const std::string PROPS_STAVES_NAME = "props_staves"; //����
const std::string PROPS_STAVES_PATH = "daojumofabang.PNG";
const std::string WEAPON_STAVES_NAME = "props_staves"; //ѡ������ʱ������ķ���ͼ��
const std::string PROPS_WOODEN_HAMMER_NAME = "props_maces"; //���ִ�
const std::string WEAPON_WOODEN_HAMMER_NAME = "props_maces"; //ѡ������ʱ������ĵ��ִ�
const std::string PROPS_WOODEN_HAMMER_PATH = "daojumuchui.PNG";
//ľ���ͷ��ȵ�ѡ�����
const std::string PROPS_SELECT_ALERT_BACKGROUND = "kuangshiyongdaoju.PNG";
const std::string PROPS_SELECT_ALERT_CONFIRM = "anniuqueding.PNG";
const std::string PROPS_SELECT_ALERT_CANCEL = "anniuquxiao.PNG";
const std::string PROPS_SELECT_ALERT_LAYERCOLOR_NAME = "select_alert_name";
const int PROPS_SELECT_ALERT_BACKGROUND_OPACITY = 80;
const cocos2d::Color4B PROPS_SELECT_ALERT_LAYER_COLOR = cocos2d::Color4B(0, 0, 0, PROPS_SELECT_ALERT_BACKGROUND_OPACITY);
const float PROPS_SELECT_ALERT_BUTTON_SELECT_SCALE = 1.1f;
const cocos2d::Vec2 PROPS_SELECT_ALERT_BACKGROUND_POS = cocos2d::Vec2(375.0f, 300.0f);
const float PROPS_SELECT_ALERT_BUTTON_X = 140.0f;
//���߼��
const std::string WOODEN_HAMMER_CAST_NODE_NAME = "bubble_cast";
const float CAST_BODY_DENSITY = 0.0f; //��������ܶ�
const float RECENT_BUBBLE_CAST_IMPULSE_Y = 3000.0f; //���С����ĳ���
//��Ļ����
const float GAME_DESIGN_RESOLUTION_WIDTH = 750.0f;//��Ʒֱ��ʿ�
const float GAME_DESIGN_RESOLUTION_HEIGHT = 1334.0f;//��Ʒֱ��ʸ�
const float GAME_ALERT_MASK_WIDTH = GAME_DESIGN_RESOLUTION_WIDTH*2;//alert��������ο�
const float GAME_ALERT_MASK_HEIGHT = GAME_DESIGN_RESOLUTION_HEIGHT*2;//��
//��������
const cocos2d::Vec2 RECENT_BUBBLE_CAST_SHAPE[] = { cocos2d::Vec2(0.0f, 100.0f),
cocos2d::Vec2(GAME_DESIGN_RESOLUTION_WIDTH / 2, 0.0f), cocos2d::Vec2(GAME_DESIGN_RESOLUTION_WIDTH / -2, 0.0f) };
const float BUBBLE_IMPULSE = 900000.0f; //����ĳ���
const int BUBBLE_IMPULSE_AFTER_VICTORY_RANDOM_X = 30000; //ʤ������С��ĳ������ֵ
const int BUBBLE_IMPULSE_AFTER_VICTORY_RANDOM_Y_MIN = 80000;
const int BUBBLE_IMPULSE_AFTER_VICTORY_RANDOM_Y_MAX = 100000;
const float GAME_MENU_SELECT_SCALE = 0.8f;    //�˵����ʱ�ķŴ����
//const float GAME_BUTTON_ZOOM_SCALE = -0.2f;    //BUTTON���ʱ�ķŴ����
const float PI = 3.14f; //Բ����
const float SQRT3 = 1.732f;//����3
const int MAP_MAX_ROW_IN_SCREEN = 10; //��Ļ�ڵ�С�������
const int DISTANCE_LINE_NUMBER = 6;   //����̨���������С������
const int FALL_DISTANCE_LINE_OFFSET_NUMBER = 5;   //����ģʽ������ƫ��
const int MAP_TOP_ROW_INDEX = -1;      //��ͼ��������������ݵ�����
const int MAP_EVEN_ROW_MAX = 11;  //��ͼż�������С�����
const int MAP_ODD_ROW_MAX = 10;   //��ͼ���������С�����
//const int MAP_TOP_ROW_INDEX = -1;     //�߽�С���������
const float MAP_BUBBLE_RADIUS = 34.0f;     //��ͼ��С�����뾶, ����ͼ�İ뾶, ��ײ����뾶������
const float MAP_BUBBLE_DIAMETER = MAP_BUBBLE_RADIUS * 2;  //ֱ��
const float SIGHTING_POINT_RADIUS = 9.0f; //��׼�ߵ�İ뾶
//const float SIGHTING_POINT_REFLECTION_OFFSET = 3.0f; //��׼�߷����λ��ƫ��
const float BUBBLE_RADIUS = 22.0f;      //С�����뾶
const float BUBBLE_BODY_DIAMETER = BUBBLE_RADIUS *2;      //С�����ֱ��
const int CAST_BODY_RADIUS = MAP_BUBBLE_RADIUS * 5;
const float MIN_MAP_DISTANCE = (MAP_BUBBLE_RADIUS * SQRT3 * DISTANCE_LINE_NUMBER);//����̨��������ľ���

const float FALL_MIN_MAP_OFFSET_DISTANCE = (MAP_BUBBLE_RADIUS * SQRT3 * FALL_DISTANCE_LINE_OFFSET_NUMBER);//����ģʽ�ľ���ƫ��
const float MAP_MOVE_SPEED = 500.0f;  //��ͼ����ƶ��ٶ�
//const float BUBBLE_DOWN_DELAY_TIME = 0.03f;  //С������ӳ�
const float BUBBLE_ELIMINATE_SCALETO = 1.5f;  //С�������ķŴ�
const cocos2d::Vec2 PHYSICS_WORLD_GRAVITY_VEC2 = cocos2d::Vec2(0, -750);  //������������
//const cocos2d::Vec2 BUBBLE_DOWN_FROM_AIR_IMPULSE_VEC2 = cocos2d::Vec2(30000, 0); //��������ʱ����ӵĳ���
const int BUBBLE_DOWN_FROM_AIR_TORQUE = 1000000.0f; //����
const int BUBBLE_DOWN_FROM_AIR_IMPULSE_MAX_X = 20000; //��������ʱ����ӵ�������
const int BUBBLE_DOWN_FROM_AIR_IMPULSE_MIN_X = 10000; //��������ʱ����ӵ���С����
const int BUBBLE_DOWN_FROM_AIR_IMPULSE_MAX_Y = -5000; //��������ʱ����ӵ�������
const int BUBBLE_DOWN_FROM_AIR_IMPULSE_MIN_Y = -10000; //��������ʱ����ӵ���С����
const float BUBBLE_DOWN_FROM_AIR_ANGULAR_VELOCITY = 5.0f;   //���ٶ�
const int LONG_CONTACT_EFFECT_DISTANCE = 15;   //����ȵ�ײ��С�����ľ���
const int SHORT_CONTACT_EFFECT_DISTANCE = 5;    //С���ȵ�ײ��С�����ľ���
const float BUBBLE_CONTACT_TIME = 0.1f;   //����ȵ�ײ��С�����Ķ���ʱ��, ��С����ͬһʱ��
const float TWO_SCORE_WIDGET_DISTANCE = 100.0f; //�����÷ֹҼ�����С����
const float SCORE_WIDGET_POSITION_OFFS = 20.0f;  //�÷ֹҼ���λ��ƫ��
const int SCORE_WIDGET_MAX_COMBO = 12;     //�÷ֹҼ������������
const int SCORE_WIDGET_BLUE_SCORE = 25;     //��ɫ�Ҽ�һ�ε÷�
const int SCORE_WIDGET_YELLOW_SCORE = 50;     //��ɫ�Ҽ�һ�ε÷�
const int SCORE_WIDGET_GREEN_SCORE = 100;     //��ɫ�Ҽ�һ�ε÷�
const float SCORE_WIDGET_COMBO_DELAY = 1.0f;  //�÷ֹҼ�ʱ��������
const int SCORE_WIDGET_NOT_COMBO_NUMBLE = 2;      //�Ҽ�������ʱ�Ƴ�������
const int BARREL_BOTTOM_SCORE_FIRST = 100;     //�����1��Ͱ�׵ĵ÷�
const int BARREL_BOTTOM_SCORE_SECOND = 500;    //�����2��Ͱ�׵ĵ÷�
const int BARREL_BOTTOM_SCORE_THIRD = 1000;   //�����3��Ͱ�׵ĵ÷�
const int BARREL_BOTTOM_SCORE_FOURTH = 500;   //�����4��Ͱ�׵ĵ÷�
const int BARREL_BOTTOM_SCORE_FIFTH = 100;    //�����5��Ͱ�׵ĵ÷�
const float ADD_PHYSICASBODY_DELAYTIME = 0.02f; //��Ӹ�����ӳ�ʱ��
const float PREPARE_RELOAD_MOVE_TIME = 0.2f;  //С��װ��ʱ�ƶ���ʱ��
const float AFTER_VECTORY_PREPARE_RELOAD_MOVE_TIME = 0.1f;  //ʤ��������С��װ��ʱ�ƶ���ʱ��
const float AFTER_VECTORY_PREPARE_REPEAT_DELAY_TIME = AFTER_VECTORY_PREPARE_RELOAD_MOVE_TIME+0.05f;  //ʤ��������С����ʱ��


const float POP_SCORE_DELAYTIME = 0.3f;                     //�����ӳ�
const float SCOREWIDGET_FLY_OUT_TIME = 1.0f;   //�Ҽ�����ʱ���ƶ���ʱ��
//const int POP_SCORE_CHARMAP_ITEMWIDTH = 28;   //�����ķ����������ֵ�item��
//const int POP_SCORE_CHARMAP_ITEMHEIGHT = 38;    //�����ķ����������ֵ�item��
//const float POP_SCOREWIDGET_SCORE_SCALETO_1_TIME = 0.05f;  //ײ���÷ֹҼ�����������һ�����ŵ�ʱ��
//const float POP_SCOREWIDGET_SCORE_SCALETO_1_NUMBLE = 0.7f;     //��һ�����ŵı���
//const float POP_SCOREWIDGET_SCORE_SCALETO_2_TIME = 0.1f;
//const float POP_SCOREWIDGET_SCORE_SCALETO_2_NUMBLE = 1.3f;
//const float POP_SCOREWIDGET_SCORE_SCALETO_3_TIME = 0.05f;
//const float POP_SCOREWIDGET_SCORE_SCALETO_3_NUMBLE = 1.0f;
//const float POP_SCOREWIDGET_SCORE_MOVE_TIME = 2.0f;    //�Ҽ��ɳ���Ļ��ʱ��
const cocos2d::Vec2 POP_SCOREWIDGET_SCORE_MOVE_VEC2 = cocos2d::Vec2(0.0f, 20.0f);  //�Ҽ����������ƶ��ľ���
const int SHOOT_BUBBLE_ENABLED_DEGREE = 20;     //�������С��������ķ���Ƕ�
const float GUNSIGHT_EXCHANGE_DISTANCE = 80.0f;  //��׼��������뾶
const float GRASS_EXCHANGE_DISTANCE = 50.0f;  //С�ݵ�����뾶
const int BLACKHOLE_BUBBLE_SWALLOW_DIRECTION = 1;
const int BLACKHOLE_BUBBLE_SWALLOW_DEGREE = 360* BLACKHOLE_BUBBLE_SWALLOW_DIRECTION; //����ڶ�С�����ת�Ƕ�
const float BLACKHOLE_BUBBLE_SWALLOW_TIME = 1.5f; //����ڶ�С�����תʱ��
const int BLACKHOLE_BUBBLE_SWALLOW_NUMBLE_MAX = 3; //�ڶ�С������������

const int INITIAL_SCORE_WIDGET_NUMBLE = 2; //����ʱ��֩������
const float INITIAL_SCORE_WIDGET_POS_Y = 200.0f; //������y�߶�
const float UI_SWIRL_ROTATIEBY_TIME = 2; //������ת��ʱ��
const float UI_SWIRL_ROTATIEBY_DEGREE = 360; //����һ��action�ĽǶ�
//const int UI_SWIRL_OPACITY = 100; //�����͸����
const int BIG_COMBO_ELIMINATE_NUMBLE = 6; //���ֱ�������Ц����
const float BUBBLS_ADJUST_MAP_DELAYETIME = 1.3f; //�ƶ����������ӳ�ʱ��
const int BUBBLE_REABOW_SEAL_COMPONENT_NUMBLE = 6; //�ʺ��ӡ�ݵ��������
const int BUBBLE_MUTIPLE_SEAL_COMPONENT_NUMBLE_1 = 0;
const int BUBBLE_MUTIPLE_SEAL_COMPONENT_NUMBLE_3 = 2;
const int BUBBLE_MUTIPLE_SEAL_COMPONENT_NUMBLE_7 = 6;
const cocos2d::Vec2 BUBBLE_MUTIPLE_SEAL_3_ANCHORPOINT(0.5, 0.75); //���ط�ӡ��ͼ��ê��
const cocos2d::Vec2 BUBBLE_IN_RAINBOW_BUBBLE_POS(-50, 20); //�ʺ��ӡ����С���λ��
const float BUBBLE_IN_RAINBOW_BUBBLE_SCALE = 0.7f; //��ӡ����С�������
const int WINDMILL_BUBBLE_TAG = 243; //�糵С���tag
const int TOP_ELIMINATE_GAME_TASK_NUMBLE = 6; //���������淨��Ŀ������
const float WINDMILL_ROTATION_ACTIONS_DURATION = 1.0f; //������ʱ��
const int WINDMILL_ROTATION_CARDINAL_SPLINE_POINT_NUMBLE = 51; //���߹켣��51����
const float WINDMILL_ROTATION_EASE_RATE = 2.0f; //EASE������ϵ��
const int WINDMILL_ROTATION_ACTION_TAG = 234;
const float WINDMILL_ROTATION_SPEED_SPEED = 2.0f;
const int COLOR_BUBBLE_TAG = 235; //��ɫС���tag
const float AFTER_VICTORY_SHOOT_BUBBLE_DELAYTIME = 0.7f;
//const float TEXTURE_SCALE = 0.4f;//������ͼ������
const std::string GAME_SCENE_SHOOT_BUBBLES_AFTER_VICTORY_SCHEDULE_KEY = "GAME_SCENE_SHOOT_BUBBLES_AFTER_VICTORY_SCHEDULE_KEY";
//�ؿ�xml����
const char BUBBLE_COLOR_IN_RANGE = '1';
const std::string STAGE_XML_FIELDS_FIRST_ELEMENT = "bubbles";
const std::string STAGE_XML_FIELDS_SECOND_ELEMENT = "data";
const std::string STAGE_XML_FIELDS_BUBBLETYPE = "type";
const std::string STAGE_XML_FIELDS_ROW = "row";
const std::string STAGE_XML_FIELDS_COL = "col";
const std::string STAGE_XML_FIELDS_CLOUD = "cloud";
const std::string STAGE_XML_FIELDS_PATH = "path";
const std::string STAGE_XML_FIELDS_BUBBLENUM = "bubbleNum";
const std::string STAGE_XML_FIELDS_STAGETYPE = "type";
const std::string STAGE_XML_FIELDS_START1 = "start1";
const std::string STAGE_XML_FIELDS_START2 = "start2";
const std::string STAGE_XML_FIELDS_START3 = "start3";
const std::string STAGE_XML_FIELDS_COLORS = "colors";
//��Ч
const std::string LIGHTNING_BUBBLE_EFFECT_PATH = "SD-TX/SD-TX.ExportJson"; //������Ч��·��
const std::string LIGHTNING_BUBBLE_EFFECT_NAME = "SD-TX"; //������Ч������
const std::string BALL_LIGHTNING_BUBBLE_EFFECT_PATH = "SDQ-TX/SDQ-TX.ExportJson"; //��������Ч��·��
const std::string BALL_LIGHTNING_BUBBLE_EFFECT_NAME = "SDQ-TX"; //��������Ч������
const float LIGHTNING_BUBBLE_EFFECT_WHITE_EFFECT_TIME = 0.1f;   //��ɫ����ʱ��
const int LIGHTNING_BUBBLE_EFFECT_BLACK_EFFECT_OPACITY = 200;
const int SPECIAL_BUBBLE_EFFECT_DURATION = -1; //������Ч��durationTo����
const float LIGHTNING_BUBBLE_EFFECT_DELAY_TIME = 0.5f;   //�������صĲ���
const std::string ONE_ROUND_BOMB_EFFECT_PATH = "qicaibaoshi TX/qicaibaoshi TX.ExportJson"; //ըһȦ��Ч��·��
const std::string ONE_ROUND_BOMB_EFFECT_NAME = "qicaibaoshi TX"; //ըһȦ��Ч������
const float ONE_ROUND_BOMB_EFFECT_DELAY_TIME = 0.1f;   //�������صĲ���
const float TWO_ROUND_BOMB_EFFECT_RIPPLE2D_DURATION = 0.8f; //ʱ��
const float TWO_ROUND_BOMB_EFFECT_RIPPLE2D_RADIUS = 120.0f; //�뾶
const int TWO_ROUND_BOMB_EFFECT_RIPPLE2D_WAVES = 1; //������
const float TWO_ROUND_BOMB_EFFECT_RIPPLE2D_AMPLITUDE = 100.0f; //����
const cocos2d::Size ACTION_3DGRID(64, 48);
const float TWO_ROUND_BOMB_EFFECT_DELAY_TIME = LIGHTNING_BUBBLE_EFFECT_DELAY_TIME;   //�������صĲ���

//const GLubyte BLACK_HOLE_SWALLOW_OPACITY_CUT = 50;
const GLubyte TEXTURE_OPACITY = 255;
//const std::string BARREL_BOTTOM_EFFECT_PATH = "diaoluo-TX/diaoluo-TX.ExportJson"; //С�����Ͱ������Ч��·��
//const std::string BARREL_BOTTOM_EFFECT_NAME = "diaoluo-TX"; //С�����Ͱ������Ч������
//const float BARREL_BOTTOM_EFFECT_POSITION_Y = 0.0f;
const std::string COLOR_BUBBLE_ELIMINATE_EFFECT_PATH = "PPX-TX/PPX-TX.ExportJson"; //��ͨС��������Ч��·��
const std::string COLOR_BUBBLE_ELIMINATE_EFFECT_NAME = "PPX-TX"; //��ͨС��������Ч��·��
//const std::string BARREL_BOTTOM_STANDBY_EFFECT_PATH = "PPP-TX/PPP-TX.ExportJson"; //Ͱ��ð����Ч��·��
//const std::string BARREL_BOTTOM_STANDBY_EFFECT_NAME = "PPP-TX"; //Ͱ��ð����Ч������
const int BARREL_BOTTOM_STANDBY_EFFECT_SPEED_SCALE = 1.7f; //������Ч��ʱ�򶯻����ٶȸı�
const float BARREL_BOTTOM_STANDBY_EFFECT_POS_Y = 90.0f; //λ��
const int BARREL_BOTTOM_STANDBY_EFFECT_DELAYTIME_MAX = 10;
const int BARREL_BOTTOM_STANDBY_BIG_EFFECT_DELAYTIME_MAX = 1; //������Ч��ʱ�򶯻������������������
const std::string BIG_COMBO_EFFECT_FIRE_ONCE_PATH = "6L-TX01/6L-TX01.ExportJson"; //����������һ�εĻ���Ч
const std::string BIG_COMBO_EFFECT_FIRE_ONCE_NAME = "6L-TX01";
const cocos2d::Vec2 BIG_COMBO_EFFECT_FIRE_ONCE_POSITION(300, 50); //λ��
const float BIG_COMBO_EFFECT_FIRE_ONCE_SPEED = 0.5f; //���������ٶ�
const std::string BIG_COMBO_EFFECT_FIRE_REPEAT_PATH = "6L-tx/6L-tx.ExportJson"; //���������������Ļ���Ч
const std::string BIG_COMBO_EFFECT_FIRE_REPEAT_NAME = "6L-tx";
const cocos2d::Vec2 BIG_COMBO_EFFECT_FIRE_REPEAT_POSITION(375, 50); //λ��
const std::string BIG_COMBO_EFFECT_POINT_PATH = "dahuo-09.png"; //���������������Ļ���Ч
const std::string BIG_COMBO_EFFECT_POINT_NAME = "big_combo_effect_point"; //���������������Ļ���Ч
const float BIG_COMBO_EFFECT_POINT_TIEM = 0.5f; //С�����Ч��ʱ��
const float BIG_COMBO_EFFECT_POINT_DELAYTIEM = 0.01f; //С�����Ч��ʱ��
const float BIG_COMBO_EFFECT_POINT_SCALETO = 0.3f; //С�����Ч��ʱ��
const float BIG_COMBO_EFFECT_POINT_MOVEBY_Y = 300.0f; //С�����Ч��ʱ��
const float BIG_COMBO_EFFECT_POINT_POS_X_MIN = 0.0f;  //�����λ�÷�Χ
const float BIG_COMBO_EFFECT_POINT_POS_X_MAX = 750.0f; //�����λ�÷�Χ
const float BIG_COMBO_EFFECT_POINT_POS_Y_MIN = -50.0f; //�����λ�÷�Χ
const float BIG_COMBO_EFFECT_POINT_POS_Y_MAX = 50.0f;  //�����λ�÷�Χ
const std::string BIG_COMBO_EFFECT_UNDER_FIRE_PATH = "DX-TX/DX-TX.ExportJson"; //����������һ�εĻ���Ч
const std::string BIG_COMBO_EFFECT_UNDER_FIRE_NAME = "DX-TX";
const cocos2d::Vec2 BIG_COMBO_EFFECT_UNDER_FIRE_POSITION(375, 50); //λ��
const float BARREL_SHAKE_MOVEBY_DISTANCE_X = 0.5f; //����Ķ�������
const float BARREL_SHAKE_MOVEBY_DISTANCE_Y = 1.5f; //����Ķ�������
const float BARREL_SHAKE_MOVEBY_DISTANCE_TIME = 0.05f; //����Ķ�������λ��ʱ��
const float BIG_BACKGROUND_EFFECT_TIME = 2.0f; //��ɫ�����Ĵ���Ч��ʱ��
const cocos2d::Color4B BIG_BACKGROUND_EFFECT_BLACK_COLOR(0, 0, 0, 200); //һ��ʼ�ĺ�ɫ�����ɫ
const cocos2d::Color4B BIG_BACKGROUND_EFFECT_BLUE_COLOR(40, 143, 212, 255); //��ɫ�����ɫ
const cocos2d::Color4B BIG_BACKGROUND_EFFECT_SMALL_BLUE_COLOR(107, 240, 255, 178); //��ɫС������ɫ
const int BIG_BACKGROUND_EFFECT_BLACK_ZORDER = 1;//��ɫ���zorder
const int BIG_BACKGROUND_EFFECT_BLACK_FADE_TAG = 101;//��ɫ���fade����Ч��tag
const float BIG_BACKGROUND_EFFECT_BLACK_TO_WHITE_TIME = 0.3f;//�ڰ�Ч����ʱ��
const float BIG_BACKGROUND_EFFECT_LEFT_TO_RIGHT_MOVE_X = -500.0f;//С�����ƶ���x����
const float BIG_BACKGROUND_EFFECT_RIGHT_TO_LEFT_MOVE_X = 500.0f;
const float BIG_BACKGROUND_EFFECT_LEFT_TO_RIGHT_POSX = -40.0f;//С����x��ʼλ��
const float BIG_BACKGROUND_EFFECT_RIGHT_TO_LEFT_POSX = 30.0f;
const int BIG_BACKGROUND_EFFECT_SMALL_BLUE_MIN_WIDTH = 10; //С������С���
const int BIG_BACKGROUND_EFFECT_SMALL_BLUE_MAX_WIDTH = 100; //С���������
const std::string RAINBOW_CHARACTOR_BG_PATH = "rainbow_charactor_bg.png";
const std::string RAINBOW_CHARACTOR_SWIRL_PATH = "rainbow_charactor_swirl.png";
const std::string BIG_BLUE_BACKGROUND_EFFECT_POINT_PATH = "Q-01.png"; //��������Ч�ϵ���Բ��
//const float RAINBOW_CHARACTOR_ARMATURE_POS_X = -20;
const float RAINBOW_CHARACTOR_ARMATURE_ENTER_FROM_LEFT_POS_X = -150.0f;
const cocos2d::Vec2 RAINBOW_CHARACTOR_ARMATURE_ENTER_FROM_LEFT_POS(-150.0f, GAME_DESIGN_RESOLUTION_HEIGHT);
const cocos2d::Vec2 RAINBOW_CHARACTOR_ARMATURE_BEZIERTO_CONTROLLPOINT_2_OFFS(-300.0f, 0.0f);
const float RAINBOW_CHARACTOR_ARMATURE_BEZIERTO_DURATION = 2.0f; //��һ�ν�����ʱ���ʱ��
const float RAINBOW_CHARACTOR_ARMATURE_MOVE_DURATION = 1.3f; //��ӡת��ʱ���ʱ��
//const std::string RAINBOW_CHARACTOR_ANIMATIOIN_STANDBY_NAME = "daiji";
const std::string RAINBOW_CHARACTOR_ANIMATIOIN_FLYING_NAME = "feixing";
const std::string RAINBOW_BUBBLE_ARMATURE_PATH = "RainbowAnimation/RainbowAnimation.ExportJson"; //�ʺ��ӡ��Ķ���
const std::string RAINBOW_BUBBLE_ARMATURE_NAME = "RainbowAnimation";
const std::string RAINBOW_BUBBLE_ARMATURE_STANDBY_NAME = "gaoguang";
const std::string RAINBOW_BUBBLE_ARMATURE_BOMB_NAME = "baozha";
//const std::string MUTIPLE_SEAL_CHARACTOR_ANIMATIOIN_STANDBY_NAME = "zhayan";
//const std::string MUTIPLE_SEAL_CHARACTOR_ANIMATIOIN_ELIMINATE_NAME = "tiaochu";
//const std::string GAME_CHARACTER_ARMATURE_LAOHU_NAME = "laohu";
//const std::string GAME_CHARACTER_LAOHU_ANIMATION_STANDBY_NAME = "daiji-01-1";
//const std::string GAME_CHARACTER_LAOHU_ANIMATION_SHOOT_BUBBLE_NAME = "rengqiu01";
const std::string GAME_CHARACTER_ANIMATION_LEGENDARY_NAME = "liulianji";
//const std::string WINDMILL_BUBBLE_DEMON_ARMATURE_PATH = "xiaoyao/xiaoyao.ExportJson"; //�糵�����Ķ���
//const std::string WINDMILL_BUBBLE_DEMON_ARMATURE_NAME = "xiaoyao";
//С�����
const int BUBBLE_BODY_MASS = 100;    //С������
const float BUBBLE_BODY_DENSITY = 0.5f;  //С���ܶ�
const float BUBBLE_PREPARE_BODY_MASS = 600.0f;  //С���ܶ�
const float BUBBLE_STATIC_BODY_RESTITUTION = 1.0f;  //С�򷴵���
const float BUBBLE_DYNAMIC_BODY_RESTITUTION = 0.7f;  //С�򷴵���
const float BUBBLE_BODY_FRICTION = 300.0f;  //С��Ħ����
const int BUBBLE_BODY_GROUP = -1;
//����߽����
const float PHYSICS_WORLD_BODY_DENSITY = 0.0f; //����߽��ܶ�
const float PHYSICS_WORLD_BODY_RESTITUTION = 1.0f; //����߽練����
const float PHYSICS_WORLD_FRICTION = 0.0f; //����߽�Ħ����
const float PTM_RATIO = 32.0f; //�����������غ����׻���
const float PHYSICS_WORLD_BODY_BORDER = 3;   //����߽�Ŀ��
//const int PHYSICS_WORLD_BODY_TAG = 233;   //����߽�Ŀ��
//�糵�߽����
const float PHYSICS_WINDMILL_BORDER_BODY_WIDTH = PHYSICS_WORLD_BODY_BORDER;
const float PHYSICS_WINDMILL_BORDER_BODY_HEIGHT = GAME_DESIGN_RESOLUTION_HEIGHT;
const cocos2d::Size PHYSICS_WINDMILL_BORDER_BODY_LEFT_SIZE(PHYSICS_WINDMILL_BORDER_BODY_WIDTH, PHYSICS_WINDMILL_BORDER_BODY_HEIGHT);
const cocos2d::Size PHYSICS_WINDMILL_BORDER_BODY_RIGHT_SIZE(PHYSICS_WINDMILL_BORDER_BODY_WIDTH, PHYSICS_WINDMILL_BORDER_BODY_HEIGHT);
const cocos2d::Size PHYSICS_WINDMILL_BORDER_BODY_TOP_SIZE(GAME_DESIGN_RESOLUTION_WIDTH, PHYSICS_WINDMILL_BORDER_BODY_WIDTH);
const cocos2d::Size PHYSICS_WINDMILL_BORDER_BODY_BOTTOM_SIZE(GAME_DESIGN_RESOLUTION_WIDTH, PHYSICS_WINDMILL_BORDER_BODY_WIDTH);

const cocos2d::Vec2 PHYSICS_WINDMILL_BORDER_BODY_LEFT_POSITION(0.0f, 710.0f);
const cocos2d::Vec2 PHYSICS_WINDMILL_BORDER_BODY_RIGHT_POSITION(GAME_DESIGN_RESOLUTION_WIDTH, 720.0f);
const cocos2d::Vec2 PHYSICS_WINDMILL_BORDER_BODY_TOP_POSITION(GAME_DESIGN_RESOLUTION_WIDTH / 2, 1165.0f);
const cocos2d::Vec2 PHYSICS_WINDMILL_BORDER_BODY_BOTTOM_POSITION(GAME_DESIGN_RESOLUTION_WIDTH / 2, 290.0f);
const cocos2d::Vec2 PHYSICS_WINDMILL_BORDER_BODY_BOTTOM2_POSITION(GAME_DESIGN_RESOLUTION_WIDTH / 2, 220.0f);
//Ͱ�߸���
const float PHYSICS_BARRELHEADEDGE_BODY_DENSITY = 0.0f;   //Ͱ�߸����ܶ�
const float PHYSICS_BARRELHEADEDGE_BODY_RESTITUTION = 1.2f; //Ͱ�߸��巴����
const float PHYSICS_BARRELHEADEDGE_BODY_FRICTION = 0.0f; //Ͱ�߸���Ħ����
//Ͱ�ײ�����
const cocos2d::Size PHYSICS_BARREL_BOTTOM_BODY_SIZE = cocos2d::Size(120, 5);
const int PHYSICS_BARREL_BOTTOM_BORDER = 2;
const float PHYSICS_BARREL_BOTTOM_BODY_DENSITY = 0.0f; //Ͱ�߸����ܶ�
const float PHYSICS_BARREL_BOTTOM_BODY_RESTITUTION = 0.0f;   //Ͱ�߸��巴����
const float PHYSICS_BARREL_BOTTOM_BODY_FRICTION = 50000.0f; //Ͱ�߸���Ħ����
//�÷ֹҼ�����
const float PHYSICS_SCORE_WIDGET_BODY_DENSITY = 0.0f;  //�÷ֹҼ������ܶ�
const float PHYSICS_SCORE_WIDGET_BODY_RESTITUTION = 1.2f;   //�÷ֹҼ����巴����
const float PHYSICS_SCORE_WIDGET_BODY_FRICTION = 10.0f;   //�÷ֹҼ�����Ħ����
const int SCORE_WIDGET_BODY_RADIUS = 15;  //�÷ֹҼ�����뾶
//��׼�����
const float PHYSICS_SIGHTING_POINT_BODY_DENSITY = 0.0f;  //�����ܶ�
const float PHYSICS_SIGHTING_POINT_BODY_RESTITUTION = 1.0f;   //���巴����
const float PHYSICS_SIGHTING_POINT_BODY_FRICTION = 0.0f;   //����Ħ����
//const float SIGHTING_POINT_BODY_RADIUS = MAP_BUBBLE_DIAMETER;  //����뾶
//�Զ����¼�������
const std::string EVENT_MAP_LOADED = "map_loaded";       //������С���ͼ
const std::string EVENT_WINDMILL_MAP_BORDER_LOADED = "event_windmill_map_border_loaded";       //���ط糵��ͼ�߽�
const std::string EVENT_FALL_MAP_BORDER_LOADED = "EVENT_FALL_MAP_BORDER_LOADED";       //���������ͼ�߽�
const std::string EVENT_TOP_ELIMINATE_BUBBLE_LOGO_LOADED = "event_top_eliminate_bubble_logo_loaded"; //���������淨 �������������logo
const std::string EVENT_INITIAL_START_NUMBLES = "event_initial_start_numbles"; //��ʼ�����ǵķ���
const std::string EVENT_BUBBLE_ELIMINATED = "bubble_shoule_eliminated"; //��Ҫ����С��
const std::string EVENT_BUBBLE_CLING = "bubble_should_cling";  //����С��
const std::string EVENT_BUBBLE_PRECLING = "event_bubble_precling";  //Ԥ����С��
const std::string EVENT_ESTIMATE_VICTORY = "event_estimate_victory";  //�ж��Ƿ�ʤ��
const std::string EVENT_WINDMILL_ROTATION = "windmill_rotation";  //�糵ת
const std::string EVENT_CAN_USED_PROPS = "EVENT_CAN_USED_PROPS"; //����ʹ�õ�����
const std::string EVENT_BUBBLE_AIR = "bubble_is_in_the_air";  //��ЩС��Ҫ������
const std::string EVENT_BUBBLE_RUN_EFFECT = "bubble_run_effect";  //С����ײ����Ч
//const std::string EVENT_SCORE_ADD = "score_add";  //���ӵ÷�
const std::string EVENT_SCORE_TEXT_UPDATE = "score_text_update";   //������ǩ����
const std::string EVENT_SHOOT_BUBBLE = "shoot_bubble";   //����С��
const std::string EVENT_EXCHANGE_BUBBLE = "exchange_bubble";  //����׼��С��
const std::string EVENT_DESTROY_BUBBLE_CLOUD = "destroy_bubble_cloud"; //�Ƴ������ϵ�����
const std::string EVENT_CHANGE_PREPARE_TYPE = "change_prepare_bubble_type"; //���ķ���С����ɫ
const std::string EVENT_BLACKHOLE_BUBBLE_ELIMINATED = "black_bubble_eliminated"; //���ķ���С����ɫ
const std::string EVENT_ADJUST_MAP_POSITION = "adjust_map_position"; //���ķ���С����ɫ
const std::string EVENT_FALL_STAGE_ADJUST_MAP_POSITION = "event_fall_stage_adjust_map_position";
const std::string EVENT_ADD_ELIMINATE_COMBO = "add_eliminate_combo"; //������������
const std::string EVENT_CUT_ELIMINATE_COMBO = "cut_eliminate_combo"; //�����������
const std::string EVENT_HAVE_USED_PROPS = "hanve_used_props"; //ʹ�������
const std::string EVENT_USE_BUBBLE_BOMB_PROPS = "use_props_bomb"; //���ʹ�ò������
const std::string EVENT_CANCEL_BUBBLE_BOMB_PROPS = "cancel_use_colorbomb"; //���ȡ��ʹ�ò������
const std::string EVENT_PROPS_SELECT_ALERT_CANCEL = "props_alert_cancel"; //����ѡ�����ȡ��
const std::string EVENT_PROPS_SELECT_ALERT_CONFIRM = "props_alert_confirm"; //����ѡ�����ȡ��
const std::string EVENT_USE_SELECTION_PROPS = "use_selection_props";  //ʹ��ѡ��ϵ�ĵ���
const std::string EVENT_SELECT_BUBBLE = "select_bubble"; //ѡ������
const std::string EVENT_FIND_BUBBLES_IN_VISIBLESIZE = "find_bubbles_in_visible"; //������Ļ�е�С��
const std::string EVENT_RECENT_BUBBLE_CAST = "evnet_recent_bubble_cast"; //������С��
const std::string EVENT_ROTATE_SIGHTING_DEVICE = "rotate_sighting_device"; //��ת��׼��
const std::string EVENT_MAIN_ROTATE_SIGHTING_DEVICE = "event_main_rotate_sighting_device"; //��ת��׼��
const std::string EVENT_TURN_ON_SIGHTING_DEVICE = "turn_on_sighting_device"; //������׼��
const std::string EVENT_TURN_OFF_SIGHTING_DEVICE = "turn_off_sighting_device"; //�ر���׼��
const std::string EVENT_SIGHTING_POINT_CONTACT_WORLD = "sighting_point_contact_world"; //��׼�������߽�
const std::string EVENT_UPDATE_COMPLETED_TASK_LABEL = "update_completed_task_label"; //�������������label
const std::string EVENT_UPDATE_BUBBLE_USE_COUNT_LABEL = "update_bubble_use_count_label"; //����С��ʹ����label
const std::string EVENT_SHOOT_PREPARE_BUBBLE = "shoot_prepare_bubble"; //�������ȥ
const std::string EVENT_ADD_AIR_BUBBLE_NUMBLE = "add_air_bubble_numble"; //���ӿ���С�������ͳ��
const std::string EVENT_CUT_AIR_BUBBLE_NUMBLE = "cut_air_bubble_numble"; //--����С�������ͳ��
const std::string EVENT_GAME_DEFEAT = "event_game_defeat"; //��Ϸʧ��
const std::string EVENT_POP_ENTER_GAME_ALERT = "event_pop_enter_game_alert"; //����������Ϸ�����
const std::string EVENT_SETTING_ALERT_CLOSE = "event_setting_alert_close"; //�ؿ�������������ر�
const std::string EVENT_FIND_THREE_BUBBLE = "EVENT_FIND_THREE_BUBBLE";  //ʹ�ü�3����
const std::string EVENT_UPDATE_SECOND_BUBBLE = "EVENT_UPDATE_SECOND_BUBBLE"; //���µڶ�С��
//const std::string EVENT_DEFEAT = "EVENT_DEFEAT"; //ʧ��
const std::string EVENT_ADD_ELIMINATE_SCORE_LABEL = "EVENT_ADD_ELIMINATE_SCORE_LABEL"; //��������ķ���label
const std::string EVENT_ADD_ELIMINATE_SCORE_LABEL_DATA_SCORE_KEY = "score_text";
const std::string EVENT_ADD_ELIMINATE_SCORE_LABEL_DATA_POS_X_KEY = "pos_x";
const std::string EVENT_ADD_ELIMINATE_SCORE_LABEL_DATA_POS_Y_KEY = "pos_y";
const std::string EVENT_UNLOCK_STAGE_MENU = "event_unlock_stage_menu"; //������ؿ���ť
const std::string EVENT_CLOCK_RANG = "event_clock_rang"; //��ʱ������
const std::string EVENT_CLOCK_CLEAR = "event_clock_clear"; //��ʱ����clear
const std::string EVENT_BUBBLE_CONTACT_BLACKHOLE = "event_bubble_contact_blackhole"; //С��ײ���ڶ�
const std::string EVENT_STAVES_SELECT_BUBBLE = "event_staves_select_bubble"; //����ѡ��С��
const std::string EVENT_BUBBLE_NO_FLASH = "event_bubble_no_flash"; //С������
const std::string EVENT_MUTIPLE_SEAL_BUBBLE_FLY = "event_mutiple_seal_bubble_fly"; //��ȶ���ɷɷ� 
const std::string EVENT_TOP_ELIMINATE_BUBBLE_FLY = "event_top_eliminate_bubble_fly";
const std::string EVENT_POP_GAME_STORE = "event_pop_game_store";
const std::string EVENT_BUY_PROPS_PAY_SUCCESS = "event_buy_props_pay_success";
const std::string EVENT_BUY_PROPS_PAY_FAIL = "event_buy_props_pay_fail";
//ѡ����Ч��key
const std::string LONG_EFFECT_BUBBLE_KEY = "long_effect";     //�������Ч
const std::string SHORT_EFFECT_BUBBLE_KEY = "short_effect";    //С������Ч
const std::string PREPARE_EFFECT_BUBBLE_KEY = "prepare_effect";    //׼��С�����Чkey
//�ַ�������                                      
const std::string BUBBLE_MAP_NODE_NAME = "bubble_map_node";  //��ͼnode
const std::string SCORE_WIDGET_NODE_NAME = "ProjectNode_1";  //�÷ֹҼ���node����
const std::string PREPARE_BUBBLE_NAME = "prepare_bubble";  //׼��С��
const std::string COLOR_BOMB_BUBBLE_NAME = "color_bomb_bubble";  //���߲���
//const std::string SECOND_PREPARE_BUBBLE_NAME = "second_bubble";  //��ѡС��
const std::string BARREL_BOTTOM_NAME = "BARREL_BOTTOM_NAME";//Ͱ��
const std::string SCORE_WIDGET_NAME = "SCORE_WIDGET";    //�÷�ײ�����
const std::string MAP_BUBBLE_NAME = ""; //��ͼ�ϵ�С������
const std::string MAP_PHYSICS_BORDER_NAME = "map_physics_border_name"; //��ͼ�ϱ߽�body����
const std::string SCORE_PROGRESS_START_1_KEY = STAGE_XML_FIELDS_START1; //¥�ϵķ����������˵�����key
const std::string SCORE_PROGRESS_START_2_KEY = STAGE_XML_FIELDS_START2; //¥�ϵķ����������˵�����key
const std::string SCORE_PROGRESS_START_3_KEY = STAGE_XML_FIELDS_START3; //¥�ϵķ����������˵�����key
//const std::string SCORE_PROGRESS_START_1_SPRITE_KEY = SCORE_PROGRESS_START_1_KEY;
//const std::string SCORE_PROGRESS_START_2_SPRITE_KEY = SCORE_PROGRESS_START_2_KEY;
//const std::string SCORE_PROGRESS_START_3_SPRITE_KEY = SCORE_PROGRESS_START_3_KEY;
//const std::string SCORE_PROGRESS_START_1_NAME = "xingxing_24"; //¥�ϵķ����������˵�����
//const std::string SCORE_PROGRESS_START_2_NAME = "xingxing_24_0"; //¥�ϵķ����������˵�����
//const std::string SCORE_PROGRESS_START_3_NAME = "xingxing_24_1"; //¥�ϵķ����������˵�����
//const std::string SCORE_PROGRESS_BORDER_NAME = "Image_2"; //¥�ϵķ����������˵ı߿�

const std::string ADD_BUTTON_NODE_NAME = "addButtonNode";
//shader
const std::string GREY_SCALE_FSH_PATH = "shaders/example_GreyScale.fsh";
const std::string NORMAL_FSH_PATH = "shaders/example_Normal.fsh";
//const std::string BLUR_FSH_PATH = "shaders/example_Blur.fsh";
//��׼��
const std::string NAME_BUBBLE_SIGHTING_POINT = "bubble_sighting_point"; //����
const std::string NAME_BUBBLE_SIGHTING_DEVICE = "bubble_sighting_device"; //����
const std::string BUBBLE_SIGHTING_POINT_PATH = "dian.png";
const cocos2d::Vec2 BUBBLE_SIGHTING_POINT_IMPULSE(0.0f, 100.0f);
const float BUBBLE_SIGHTING_POINT_DELAYTIME = 0.5f;
const int BUBBLE_SIGHTING_POINT_NUMBLE = 15;
const float BUBBLE_SIGHTING_POINT_MOVEBY_Y = 1334.0f;
const float BUBBLE_SIGHTING_POINT_MOVEBY_TIME = 12.0f; 
const float BUBBLE_SIGHTING_POINT_CONTACT_VISIBLE_OFFSET = 140.0f; //����С��֮��Ŀ��Ӽ���ʱ��λ�����
const int BUBBLE_SIGHTING_DEVICE_TOTAL = 4; //һ����5����
const int BUBBLE_SIGHTING_DEVICE_UNUSED_PROPS_TOTAL = 1; //��ʹ�õ���, һ��2��
const float BUBBLE_SIGHTING_DEVICE_GO_AWAY_Y = 2000.0f; //��Զ��
const float BUBBLE_SIGHTING_DEVICE_MAX_POS_Y_OFFSET = 22.0f; //ƫ�����
//ui�ؼ�������
const std::string UI_NAME_GAME_PLAY_AREA_NODE = "csb_node";
const std::string UI_NAME_GUNSIGHT = "fashetaishang_38"; //��׼��
const std::string UI_NAME_TOP_PANEL = "uishang_5";     //������Ϣ��
const std::string UI_NAME_PAD = "fashetaixia_27";    //��׼������Ļ�̨
const std::string UI_NAME_SCORE_TEXT = "AtlasLabel_2";    //��Ϸ�����еķ�����ǩ
//const std::string UI_NAME_SCORE_PROGRESS_TIMER = "LoadingBar_1"; //��Ϸ�����еķ���������
const std::string UI_NAME_TOP_UI_BACKGROUND = "top_ui_bg";     //����ui�ı���
const std::string UI_NAME_PROPS_BACKGROUND_FIRST = "props_1_bg";      //����1�ı���
const std::string UI_NAME_PROPS_BACKGROUND_SECOND = "props_2_bg";      //����2�ı���
const std::string UI_NAME_PROPS_BACKGROUND_THIRD = "props_3_bg";      //����3�ı���
const std::string UI_NAME_PROPS_BACKGROUND_FOURTH = "props_4_bg";      //����4�ı���
const std::string UI_NAME_GUNSIGHT_SWIRL = "gunsight_swirl";      //����̨�ϵ�����
const std::string UI_NAME_BIG_COMBO_ELIMINATE = "big_combo_eliminate";      //������
const std::string UI_NAME_WINDMILL_PIN_NODE = "windmill_pin_node"; //�糵�Ĺؽ�pin��node
const std::string UI_NAME_GAME_VICTORY_ALERT = "UI_NAME_GAME_VICTORY_ALERT"; //ʤ����������
//���沿�ֵ�ui����
const std::string UI_NAME_BARRELHEAD_BORDER_FIRST = "Node_7";       //��������1��Ͱ�߽ڵ�
const std::string UI_NAME_BARRELHEAD_BORDER_SECOND = "Node_8";        //��������2��Ͱ�߽ڵ�
const std::string UI_NAME_BARRELHEAD_BORDER_THIRD = "Node_9";       //��������3��Ͱ�߽ڵ�
const std::string UI_NAME_BARRELHEAD_BORDER_FOURTH = "Node_10";       //��������4��Ͱ�߽ڵ�
const std::string UI_NAME_BARRELHEAD_BORDER_FIFTH = "Node_11";      //��������5��Ͱ�߽ڵ�
const std::string UI_NAME_BARRELHEAD_BORDER_SIXTH = "Node_12";      //��������6��Ͱ�߽ڵ�
const std::string UI_NAME_BARREL_BOTTOM_FIRST = "Node_1";       //�����1��Ͱ��
const std::string UI_NAME_BARREL_BOTTOM_SECOND = "Node_2";       //�����2��Ͱ��
const std::string UI_NAME_BARREL_BOTTOM_THIRD = "Node_3";        //�����3��Ͱ��
const std::string UI_NAME_BARREL_BOTTOM_FOURTH = "Node_4";        //�����4��Ͱ��
const std::string UI_NAME_BARREL_BOTTOM_FIFTH = "Node_5";        //�����5��Ͱ��
const std::string UI_NAME_WINDMILL_BORDER = "windmill_border";//�糵��ͼ�ı߽�
const std::string UI_NAME_FALL_BOTTOM_BORDER = "UI_NAME_FALL_BOTTOM_BORDER";//����ģʽ�ײ��ı߽�
//���������ɫ�Ķ�������
const std::string BUBBLE_ANIMATION_STANDBY_NAME_1 = "daiji-zhayan";
const std::string BUBBLE_ANIMATION_STANDBY_NAME_2 = "chuancha";
const std::string BUBBLE_ANIMATION_CONTACT_NAME = "aida";
const std::string BUBBLE_ANIMATION_VICTORY_NAME = "siwang";
const std::string BUBBLE_ANIMATION_DEFEAT_NAME = "shibai";
const std::string BUBBLE_ANIMATION_NOOP_NAME = "wucaozuo";
//�糵С��
//const std::string UI_NAME_WINDMILL_BUBBLE_FLYING_HEAD_PATH = "XiaoYao-tou.png";
//const std::string UI_NAME_WINDMILL_BUBBLE_FLYING_BODY_PATH = "XiaoYao-body.png";
//const std::string UI_NAME_WINDMILL_BUBBLE_FLYING_MOTIONSTREAK_PATH = "XiaoYao-streak.png";
//const float WINDMILL_BUBBLE_FLYING_HEAD_POS_Y = 40.0f;
//const float WINDMILL_BUBBLE_FLYING_BODY_POS_Y = -40.0f;
//const float WINDMILL_BUBBLE_FLYING_INITIAL_SCALE = 0.3f; //��ʼ��С
//const float WINDMILL_BUBBLE_FLYING_FINAL_SCALE = 1.3f; //����С
//const float WINDMILL_BUBBLE_FLYING_ARCHIMEDEAN_SPIRAL_A = 10.0f; //��ʽ�Ĳ���a
//const float WINDMILL_BUBBLE_FLYING_ARCHIMEDEAN_SPIRAL_B = 1.0f;
//const int WINDMILL_BUBBLE_FLYING_ARCHIMEDEAN_SPIRAL_THETA = 430;
//const int WINDMILL_BUBBLE_FLYING_ARCHIMEDEAN_SPIRAL_DIRECTION = 1; //����
//const float WINDMILL_BUBBLE_FLYING_ACTION_DURATION = 1.5f;
//������������
const float GAME_SCORE_PROGRESS_TIMER_PER_INCREASE_PERCENT = 1.5f; // ÿ֡���ӵİٷֱ�
const float GAME_SCORE_PROGRESS_TIMER_BACK_PERCENT = 3.0f;
const std::string GAME_SCORE_PROGRESS_SCHEDULE_KEY = "increase_progress";
//��Ϸ��ͣ���
const std::string GAME_PAUSE_ALERT_BIG_BACKGROUND_PATH = "kuang.png"; //�������ı��� ��ߴ�
const std::string GAME_PAUSE_ALERT_BACKGROUND_PATH = GAME_PAUSE_ALERT_BIG_BACKGROUND_PATH; //�������ı���
const float GAME_PAUSE_ALERT_BACKGROUND_SCALE_Y = 0.83f;
const std::string GAME_PAUSE_ALERT_TOP_BACKGROUND_PATH = "guanka.png"; //������ͣ�ı���
const int GAME_ALERT_TOP_BACKGROUND_TAG = 123;
const int GAME_ALERT_BIG_BACKGROUND_TAG = 122;
const cocos2d::Color4B GAME_PAUSE_ALERT_PAUSE_LABEL_COLOR(35, 157, 142, 255);
const float GAME_PAUSE_ALERT_PAUSE_LABEL_FONTSIZE = 50.0f; //�����С
//const float GAME_VICTORY_ALERT_SCORENUMBLE_LABEL_FONTSIZE = 80.0f; //�����С
const std::string GAME_PAUSE_ALERT_MUSIC_ICON_PATH = "yinyue.png"; //����ͼ��
//const float GAME_PAUSE_ALERT_MUSIC_ICON_POSITION_Y = -38.48f;
const std::string GAME_PAUSE_ALERT_EFFECT_ICON_PATH = "yinxiao.png"; //��Чͼ��
const cocos2d::Vec2 GAME_PAUSE_ALERT_EFFECT_ICON_POSITION(-120.0f, 70.0f);
const std::string GAME_PAUSE_ALERT_VOLUME_SWITCH_BACKGROUND_PATH = "vol_switch_bg.png";
const std::string GAME_PAUSE_ALERT_SIMPLE_SWITCH_MASKSPRITE_PATH = "yinxk.png";
const std::string GAME_PAUSE_ALERT_VOLUME_SWITCH_THUMBSPRITE_PATH = "yinxan.png";
const float GAME_PAUSE_ALERT_EFFECT_SWITCH_POSITION_X = 92.66f;  //��Ч���ص�x����
const std::string GAME_PAUSE_ALERT_BACK_BUTTON_PATH = "guanb.png"; //���ذ�ť
const float GAME_PAUSE_ALERT_BACK_BUTTON_POSITION_X = -166.51f;  //���ذ�ťx����
const std::string GAME_PAUSE_ALERT_RESTART_BUTTON_PATH = "chongw.png"; //���水ť
const std::string GAME_PAUSE_ALERT_RESUME_BUTTON_PATH = "jixu.png"; //���ذ�ť
const float GAME_PAUSE_ALERT_RESUME_BUTTON_POSITION_X = 166.51f;  //���ذ�ťx����
const cocos2d::Vec2 GAME_PAUSE_ALERT_BOTTOM_MENU_POSITION(0.0f, -179.0f);
const std::string GAME_ALERT_CANCEL_BUTTON_PATH = "guanbi.png"; //ȡ����ť
const cocos2d::Vec2 GAME_ALERT_CANCEL_BUTTON_POSITION(270.0f, 350.0f);
const std::string GAME_ALERT_STORE_BUTTON_PATH = "shangc.png"; //�̳ǰ�ť
const std::string GAME_DEFEAT_ALERT_CHARACTOR_PATH = "shibai.png"; //ʧ������ϵ����ﰴť
const cocos2d::Vec2 GAME_PAUSE_ALERT_DEFEAT_CHARACTOR_POSITION(0.0f, 50.0f);
const float GAME_PAUSE_ALERT_DEFEAT_CHARACTOR_SCALE = 0.7f;
const cocos2d::Vec2 GAME_DEFEAT_ALERT_REPLAY_POSITION(100.0f, -70.0f);
const cocos2d::Vec2 GAME_DEFEAT_ALERT_STORE_POSITION(-100.0f, GAME_DEFEAT_ALERT_REPLAY_POSITION.y);
const std::string GAME_DEFEAT_ALERT_COMMODITY_BACKGROUND_PATH = "djkuang.png"; //�м��С���
const cocos2d::Vec2 GAME_VICTORY_ALERT_REWARDS_BACKGROUND_POSITION(10.0f, -100.0f);
const std::string GAME_COMMODITY_TEN_BUBBLE_PATH = "addBubbleNumble.png";
const std::string GAME_ALERT_CONTINUE_BUTTON_PATH = "jixu1.png";
const std::string GAME_ALERT_COMMODITY_TEN_BUBBLE_PRICE_BACKGROUND_PATH = GAME_PAUSE_ALERT_VOLUME_SWITCH_BACKGROUND_PATH; //�۸�����ı���
const std::string GAME_DIAMOND_PATH = "zuans.png"; //שʯ
const float GAME_VICTORY_ALERT_COIN_POSITION_PERCENT_X = 0.4f;
const std::string GAME_FATIGUE_PATH = "xin.png"; //ƣ��
const float GAME_VICTORY_ALERT_FATIGUE_POSITION_PERCENT_X = 0.7f;
const float GAME_DEFEAT_ALERT_BUY_TEN_BUBBLE_LABEL_FONTSIZE = 40.0f;
const float GAME_DEFEAT_ALERT_BUY_TEN_BUBBLE_LABEL_NUMBER_OF_LINES = 11.0f;
const cocos2d::Size GAME_DEFEAT_ALERT_BUY_TEN_BUBBLE_LABEL_DIMENSIONS = cocos2d::Size(GAME_DEFEAT_ALERT_BUY_TEN_BUBBLE_LABEL_FONTSIZE*GAME_DEFEAT_ALERT_BUY_TEN_BUBBLE_LABEL_NUMBER_OF_LINES, 0.0f);
const cocos2d::Color4B GAME_DEFEAT_ALERT_BUY_TEN_BUBBLE_LABEL_COLOR(1, 94, 208, 255);
const cocos2d::Vec2 GAME_DEFEAT_ALERT_BUY_TEN_BUBBLE_LABEL_POSITION(0.0f, 180.0f);
const cocos2d::Vec2 GAME_VICTOR_ALERT_REPLAY_POSITION(GAME_PAUSE_ALERT_BACK_BUTTON_POSITION_X, GAME_DEFEAT_ALERT_REPLAY_POSITION.y);
const cocos2d::Vec2 GAME_VICTOR_ALERT_STORE_POSITION(0.0f, GAME_DEFEAT_ALERT_REPLAY_POSITION.y);
const cocos2d::Vec2 GAME_VICTOR_ALERT_NEXT_POSITION(GAME_PAUSE_ALERT_RESUME_BUTTON_POSITION_X, GAME_DEFEAT_ALERT_REPLAY_POSITION.y);
const std::string GAME_VICTORY_ALERT_NEXT_BUTTON_PATH = GAME_PAUSE_ALERT_RESUME_BUTTON_PATH; //��һ�ذ�ť
const std::string GAME_VICTORY_ALERT_FLASH_LIGHT_BACKGROUND_PATH = "dikuang.png"; //�������ı���
const std::string GAME_VICTORY_ALERT_FLASH_LIGHT_PATH = "guang.png"; //����
const float GAME_VICTORY_ALERT_FLASH_LIGHT_ROTATEBY_DURATION = 5.0f;
const float GAME_VICTORY_ALERT_FLASH_LIGHT_ROTATEBY_DELTAANGLE = 360.0f;
//const cocos2d::Vec2 GAME_VICTORY_ALERT_SCORE_LABEL_POSITION(0.0f, 30.0f); //��������λ��
//const cocos2d::Vec2 GAME_VICTORY_ALERT_SCORE_LABEL_TEXT_POSITION(0.0f, 100.0f); //����: DEλ��
const cocos2d::Vec2 GAME_VICTORY_ALERT_SAMSUNG_POSITION(0.0f, 180.0f); //����λ��
const float GAME_VICTORY_ALERT_ADD_SCORE_LABEL_POSITION_PERCENT_X = 0.5f; //+180���
const float GAME_VICTORY_ALERT_ADD_FATIGUE_LABEL_POSITION_PERCENT_X = 0.8f; //+1����
const float GAME_SAMSUNG_TWO_SIDES_ROTATIOIN = 25.0f;
//const std::string ALERT_REPLAY_BUTTON_NAME = "Button_1";
//GameBaseAlert
const std::string GAME_BASE_ALERT_NAME = "GAME_BASE_ALERT_NAME";
//GamePauseAlert
const float GAME_PAUSE_ALERT_VOL_POS_Y = 60.0f;
//StageSelectionMenu
//const float STAGE_SELECTION_MENU_SCALE = 0.7f;
//const float STAGE_SELECTION_MENU_SAMSUNG_SCALE = 0.5f;
//const float STAGE_SELECTION_MENU_THE_BLINK_FADE_DURATION = 0.75f;
//GameStageSelectionCell
const int GAME_STAGE_SELECTION_CELL_MENU_POSITION_NODE_TAG_BEGIN = 1;  //tage��1��ʼ
const int GAME_STAGE_SELECTION_CELL_NUMBLE_BEGIN = 0; //cell��0��ʼ
const int GAME_STAGE_NUMBLE_BEGIN = 1; //�ؿ���1��ʼ
const float GAME_STAGE_SELECTION_CELL_SCALE = 0.73f;
//GameStageSelectionScene
const std::string GAME_STAGE_SELECTION_SCENE_NAME = "game_stage_selection_scene";
//const float GAME_STAGE_SCROLLVIEW_CELL_HEIGHT = 745.0f;
//const float GAME_STAGE_SCROLLVIEW_CELL_BACKGROUND_HEIGHT = 1024.0f;
//const float GAME_STAGE_SCROLLVIEW_CELL_OFFSET_OFFSET = GAME_DESIGN_RESOLUTION_HEIGHT - GAME_STAGE_SCROLLVIEW_CELL_BACKGROUND_HEIGHT;
//EnterGameAlert
const std::string ENTER_GAME_ALERT_CHARACTOR_PATH = "juese.png";
const int ENTER_GAME_ALERT_CHARACTOR_TAG = 124;
const cocos2d::Vec2 ENTER_GAME_ALERT_CHARACTOR_POSITION(5.0f, 84.0f);
const std::string ENTER_GAME_ALERT_PROPS_BACKGROUND_PATH = "djk.png";
const std::string ENTER_GAME_ALERT_BEGIN_BUTTON_PATH = "kaishi.png";
const float ENTER_GAME_ALERT_BEGIN_BUTTON_POSITION_Y = -240.0f;
const std::string ENTER_GAME_ALERT_PROPS_LABEL_BACKGROUND_PATH = GAME_DEFEAT_ALERT_COMMODITY_BACKGROUND_PATH;
const float ENTER_GAME_ALERT_PROPS_LABEL_FONTSIZE = 35.0f;
const float MOUSE_SCROLL_Y_SENSITIVITY = 50.0f; //������ϵ��
//EnterGamePropsView
const std::string ENTER_GAME_PROPS_VIEW_SIGHT_PROPS_PATH = "fzx.png"; //��׼��
const std::string ENTER_GAME_PROPS_VIEW_ADD_SPECIAL_BUBBLE_PROPS_PATH = "yaoshui.png"; //����������
const std::string ENTER_GAME_PROPS_VIEW_BACKGROUND_PATH = "daojd.png";
//ÿ��������Ӧ����Ϸ����
const std::string GAME_SCENE_BACKGROUND_PATH = "res/gameBackground.plist";
//GameSettingAlert
const std::string GAME_SETTING_ALERT_TEXTFIELD_BACKGROUND_PATH = "shurk.png";
const std::string GAME_SETTING_ALERT_PORTRAIT_PATH = "touxiang.png";
const std::string GAME_SETTING_ALERT_HELP_MENU_BACKGROUND_PATH = GAME_DEFEAT_ALERT_COMMODITY_BACKGROUND_PATH;
const std::string GAME_SETTING_ALERT_HELP_MENU_PATH = "bangz.png";
const std::string GAME_SETTING_ALERT_PROPS_MENU_PATH = "daoju.png";
const std::string GAME_SETTING_ALERT_ABOUT_MENU_PATH = "guanyu.png";
//PropsNumbleShow
const std::string PROPS_NUMBLE_LABEL_PATH = "fonts/shuzibiaoqian.png";
const int PROPS_NUMBLE_LABEL_ITEM_WIDTH = 16;
const int PROPS_NUMBLE_LABEL_ITEM_HEIGHT = 30;
//GamePropsNumbleView
const std::string GAME_PROPS_NUMBLE_VIEW_TICK_PATH = "duigou.png";
const float GAME_PROPS_NUMBLE_VIEW_TICK_POS_Y = 5.0f;
const float GAME_PROPS_NUMBLE_VIEW_BACKGROUND_SCALE = 0.65f;
//GameTextInfo
const std::string GAME_TEXT_INFO_PLIST_CHINESE_PATH = "res/zh.plist";
const std::string GAME_TEXT_INFO_PLIST_ENGLISH_PATH = "res/en.plist";
const std::string GAME_COMMODITY_PLIST_PATH = "res/commodity.plist";
const std::string GAME_TEXT_PAUSE_KEY = "pause";
const std::string GAME_TEXT_SETTING_KEY = "setting";
const std::string GAME_TEXT_NICKNAME_KEY = "nickname";  //�ǳ�
const std::string GAME_TEXT_VOLUME_ON_KEY = "volume_on";
const std::string GAME_TEXT_VOLUME_OFF_KEY = "volume_off";
const std::string GAME_TEXT_BUY_BUBBLE_KEY = "add_ten_bubble";
const std::string GAME_TEXT_BUY_BUBBLE_LABEL_KEY = "buy_ten_bubble_label";
const std::string GAME_TEXT_REWARDS_KEY = "rewards_label";
const int GAME_TEXT_REWARDS_LABEL_OPACITY = 180;
const float GAME_TEXT_REWARDS_LABEL_POSITION_PERCENT_X = 0.2f;
//const std::string GAME_TEXT_SCORE_KEY = "score_label";
const std::string GAME_TEXT_TOP_ELIMINATE = "kTopEliminate";      //������������
const std::string GAME_TEXT_RESCUE_ANIMAL = "kRescueAnimal";                   //��ȶ���
const std::string GAME_TEXT_BEAT_THE_ROBBER = "kDestroyRainbowSeal";                     //����ǿ��
const std::string GAME_TEXT_RESCUE_GHOST = "kWindmill";                                           //�������
const std::string COMMODITY_COIN_KEY = "coin";
const std::string COMMODITY_DIAMOND_KEY = "diamond";
const std::string GAME_TEXT_SELECT_PROPS_LABEL_KEY = "choose_props";
//ColorBubble
const float ENTER_PROPS_ACTION_DURATION = 1.0f; //�������ߵĶ���ʱ��
//EnterPropsViewManager
const int ADD_BUBBLE_NUMBLE_PROPS_NUMBLE = 10;
//zorder
const int UI_ZORDER_MAP_BUBBLE = -2;  //С���ͼ csb_node
const int UI_ZORDER_DOWN_AIR_BUBBLE = UI_ZORDER_MAP_BUBBLE + 1;    //����С��
const int UI_ZORDER_BACKGROUND = -4;                       //����  
const int UI_ZORDER_PROPS_SELECT_ALERT = UI_ZORDER_MAP_BUBBLE - 1; //����ѡ�����
const int UI_ZORDER_PREPARE_BUBBLE = UI_ZORDER_PROPS_SELECT_ALERT - 1;   //׼��С��
const int UI_ZORDER_SWIRL = UI_ZORDER_PREPARE_BUBBLE - 1; //����
const int UI_ZORDER_GUNSIGHT = UI_ZORDER_SWIRL - 1;   //��׼��
const int UI_ZORDER_SIGHTING_DEVICE = UI_ZORDER_GUNSIGHT - 1; //��׼����
const int UI_ZORDER_PAD = UI_ZORDER_GUNSIGHT;      //��׼������Ļ�̨
const int UI_ZORDER_GRASS = UI_ZORDER_GUNSIGHT;      //С��
const int UI_ZORDER_BARRELBOTTOM = UI_ZORDER_DOWN_AIR_BUBBLE - 1;
const int UI_ZORDER_BARRELHEAD_NODE = UI_ZORDER_BARRELBOTTOM - 1;   //Ͱ��
const int UI_ZORDER_BARREL_NUMBLE_NODE = UI_ZORDER_BARRELHEAD_NODE;   //Ͱ��
//const int UI_ZORDER_BARRELHEAD_FIRST = UI_ZORDER_BARRELBOTTOM - 3;   //Ͱ�Ǵ�������һ
//const int UI_ZORDER_BARRELHEAD_SECOND = UI_ZORDER_BARRELHEAD_FIRST + 1;
//const int UI_ZORDER_BARRELHEAD_THIRD = UI_ZORDER_BARRELHEAD_SECOND + 1;
//const int UI_ZORDER_BARRELHEAD_FOURTH = UI_ZORDER_BARRELHEAD_SECOND;
//const int UI_ZORDER_BARRELHEAD_FIFTH = UI_ZORDER_BARRELHEAD_FIRST;    //�����������Ͱ��
const int UI_ZORDER_MENU = 1;    //�˵��Ͱ�ť
const int UI_ZORDER_GUNSIGHT_SWIRL = UI_ZORDER_GUNSIGHT + 1; //��̨�ϵ�����
const int UI_ZORDER_ANIMATION_BIG_ELIMINATE_EFFECT_ONCE = UI_ZORDER_BACKGROUND; //������ʱ�����Ĳ���һ�ε���Ч
const int UI_ZORDER_ANIMATION_BIG_ELIMINATE_EFFECT_REPEAT = UI_ZORDER_MENU; //������ʱ�������������ŵ���Ч
const int UI_ZORDER_MENU_INFO = 1;    //������Ϣ֮���
//const float UI_GLOBALZORDER_LIGHTING_EFFECT_BACKGROUND = 1.1f; //������Ч�ĺ�ɫ����
//const float UI_GLOBALZORDER_LIGHTING_EFFECT = 10.5f; //������Ч
//��ײ����
const int BITMASK_BUBBLE_STATIC_CATEGORY = 0x10001; //С��̬�������������
const int BITMASK_BUBBLE_STATIC_COLLISION = 0x0001; //С��̬�������ײ����
const int BITMASK_BUBBLE_STATIC_CONTACTTEST = 0x10001; //С��̬������¼�����
                                             
const int BITMASK_BUBBLE_DYNAMIC_CATEGORY = 0x0010; //С��̬�������������
const int BITMASK_BUBBLE_DYNAMIC_COLLISION = 0x0100; //С��̬�������ײ����
const int BITMASK_BUBBLE_DYNAMIC_CONTACTTEST = 0x0100; //С��̬������¼�����

const int BITMASK_BUBBLE_PREPARE_CATEGORY = 0x100001; //׼��С��������������
const int BITMASK_BUBBLE_PREPARE_COLLISION = 0x0001; //׼��С��������ײ����
const int BITMASK_BUBBLE_PREPARE_CONTACTTEST = 0x10001; //׼��С�������¼�����

const int BITMASK_BARRELHEADEDGE_CATEGORY = 0x0100; //Ͱ�Ǳ߸������������
const int BITMASK_BARRELHEADEDGE_COLLISION = 0x0010; //Ͱ�Ǳ߸������ײ����
const int BITMASK_BARRELHEADEDGE_CONTACTTEST = 0x0001; //Ͱ�Ǳ߸�����¼�����

const int BITMASK_BARRELBOTTOM_CATEGORY = 0x0100;//Ͱ�׸������������
const int BITMASK_BARRELBOTTOM_COLLISION = 0x0000; //Ͱ�׸������ײ����
const int BITMASK_BARRELBOTTOM_CONTACTTEST = 0x0010;//Ͱ�׸�����¼�����

const int BITMASK_SCORE_WIDGET_CATEGORY = 0x0100; //�÷ֹҼ��������������
const int BITMASK_SCORE_WIDGET_COLLISION = 0x0010;//�÷ֹҼ��������ײ����
const int BITMASK_SCORE_WIDGET_CONTACTTEST = 0x0010;//�÷ֹҼ�������¼�����

const int BITMASK_PHYSICS_WORLD_CONTACTTEST = 0x1000;//���������¼�����

const int BITMASK_WINDMILL_BORDER_CATEGORY = 0x10000;//�糵��ͼ�߽����������
const int BITMASK_WINDMILL_BORDER_COLLISION = 0x00000; //�糵��ͼ�߽����ײ����
const int BITMASK_WINDMILL_BORDER_CONTACTTEST = 0x10000;//�糵��ͼ�߽���¼�����
const int BITMASK_WINDMILL_BOTTOM_BORDER_CONTACTTEST = 0x100000;//�±߷糵��ͼ�߽���¼�����

const int BITMASK_SIGHTING_POINT_INITIAL_CATEGORY = 0x0001; //��׼��������������
const int BITMASK_SIGHTING_POINT_INITIAL_CONTACTTEST = 0x0001;//��׼�������¼�����
const int BITMASK_SIGHTING_POINT_CATEGORY = 0x0001; //��׼��������������
const int BITMASK_SIGHTING_POINT_CONTACTTEST = 0x0001;//��׼�������¼�����

const int BITMASK_FALL_BOTTOM_BORDER_CONTACTTEST = 0x10000;//����ģʽ�ײ��߽���¼�����

namespace bubble_second {
    class BaseBubble;
    typedef std::map<int, cocos2d::Map<int, BaseBubble*>> BubbleSpriteMap;
    typedef cocos2d::Vector<BaseBubble*> BubbleVector;
    typedef std::vector<cocos2d::Vec2> BubbleIndexVector;
    typedef std::map<std::string, BubbleVector> BubbleVectorMap;
    //struct StageData
    //{
    //    int cell_numble = 0;
    //    int level_numble = 0;
    //};
}

enum BubbleType
{//��ɫ���ݵ���ɫ����
    kBubbleTransparent = -9, //�����͵�����
    kBubbleNoCloud = -1,
    kBubbleYellow = 0,
    kNormalColorFirst = kBubbleYellow,
    kBubblePurple,
    kBubbleBlue,
    kBubbleRed,
    kBubbleGreen,
    kBubbleOrange,
    kBubblePink = 6,
    kNormalColorLast = kBubblePink,
    kBubbleLightning = 7,
    kBubbleDarkCloud = 8,
    kBubbleBlackHole = 9,
    kBubbleBombBomb = 10,
    kBubbleColorBomb = 11,
    kBubbleBombBombProperty =12,
    kBubbleRainbowSeal = 13,
    kBubbleComponentFirst = kBubbleRainbowSeal,
    kBubbleComponent,
    kBubbleMutipleSeal = 15,
    kBubbleMutipleSeal1, //16
    kBubbleMutipleSeal3, //17
    kBubbleMutipleSeal7 = 18,
    kBubbleComponentLast = kBubbleMutipleSeal7,
    kBubbleRandomColor,
    kBubbleWindmill,
    kBubbleAddNumbleBubble
};

enum ScoreWidgetType
{//�Ҽ�����
    kScoreWidgetLow = 0,
    kScoreWidgetMiddle,
    kScoreWidgetHigh,
    kScoreWidgetTypeTotal
};

enum StageType
{
    kTopEliminate = 1<<0,
    kRescueAnimal = 1<<1,
    kDestroyRainbowSeal = 1 << 2,
    kWindmill = 1 << 3,
    kBubbleFall = 1 << 4
};
const std::string STAGETYPE_TEXTURE_TOPELIMINATE_PATH = "wanftb3.png";
const std::string STAGETYPE_TEXTURE_RESCUEANIMAL_PATH = "wanftb2.png";
const std::string STAGETYPE_TEXTURE_DESTROYRAINBOWSEAL_PATH = "wanftb4.png";
const std::string STAGETYPE_TEXTURE_WINDMILL_PATH = "wanftb1.png";
#endif //_BUBBLE_SECOND_CONSTANT_H_