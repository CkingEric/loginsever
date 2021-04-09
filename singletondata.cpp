#include "singletondata.h"

SingletonData *SingletonData::instance()
{
    return _instance;
}

SingletonData::SingletonData()
{

}
SingletonData* SingletonData::_instance=new SingletonData();
