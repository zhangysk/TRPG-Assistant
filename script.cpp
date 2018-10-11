#include "script.h"

namespace ptzs {

void Script::scriptSaveAll(QString path){
/*              这个函数用来转存部分需要转存的文件，如图片、音乐等                                   */
/*                              创建正确的文件夹目录                                            */
    QString indexPath = path + "/" + this->getName();
    QString mapPath = indexPath + "/maps";
    QString normalScenesPath = indexPath + "/normalScenes";
    QString battleScenesPath = indexPath + "battleScenes";
    QString keyNpcPath = indexPath + "/keyNpc";
    QString normalNpcPath = indexPath + "/normalNpc";
/*                              转存音乐和图片                                                  */
    QString counter = "1";
    //转存地图
    for(int i = 0; i < this->maps.size(); i++){
        QFileInfo fileInfo(this->getMap(i)->getPicFile());
        QString fileSuffix = fileInfo.suffix();
        QString tmpPath = mapPath + this->getMap(i)->getName() + "." + fileSuffix;
        counter = counter + 1;
        QFile::copy(this->getMap(i)->getPicFile(),tmpPath);
    }

    for(int i = 0; i < this->battleScene.size(); i++){
        QString tmpPath = battleScenesPath + this->getBattleScene(i)->getName();
        for(int j = 0; j < this->getBattleScene(i)->picNum(); j++){
            QFileInfo fileInfo(this->getBattleScene(i)->getPics()->at(j));
            QString fileSuffix = fileInfo.suffix();
            QString tmpPath2 = tmpPath + "/pic" + counter + "." + fileSuffix;
            QFile::copy(this->getBattleScene(i)->getPics()->at(j),tmpPath2);
        }
        for(int j = 0; j < this->getBattleScene(i)->musicNum(); j++){
            QFileInfo fileInfo(this->getBattleScene(i)->getPics()->at(j));
            QString fileSuffix = fileInfo.suffix();
            QString tmpPath2 = tmpPath + "/music" + counter + "." + fileSuffix;
            QFile::copy(this->getBattleScene(i)->getPics()->at(j),tmpPath2);
        }
    }
    for(int i = 0; i < this->normalScene.size(); i++){
        QString tmpPath = normalScenesPath + this->getNormalScene(i)->getName();
        for(int j = 0; j < this->getNormalScene(i)->picNum(); j++){
            QFileInfo fileInfo(this->getNormalScene(i)->getPics()->at(j));
            QString fileSuffix = fileInfo.suffix();
            QString tmpPath2 = tmpPath + "/pic" + counter + "." + fileSuffix;
            QFile::copy(this->getNormalScene(i)->getPics()->at(j),tmpPath2);
        }
        for(int j = 0; j < this->getNormalScene(i)->musicNum(); j++){
            QFileInfo fileInfo(this->getNormalScene(i)->getPics()->at(j));
            QString fileSuffix = fileInfo.suffix();
            QString tmpPath2 = tmpPath + "/music" + counter + "." + fileSuffix;
            QFile::copy(this->getNormalScene(i)->getPics()->at(j),tmpPath2);
        }
    }
    for(int i = 0; i < this->keyNpc.size(); i++){
        QFileInfo fileInfo(this->getKeyNPC(i)->getAvatar());
        QString fileSuffix = fileInfo.suffix();
        QString tmpPath = keyNpcPath + this->getKeyNPC(i)->getName() + "." + fileSuffix;
        QFile::copy(this->getKeyNPC(i)->getAvatar(),tmpPath);
    }
    for(int i = 0; i < this->normalNpc.size(); i++){
        QFileInfo fileInfo(this->getNormalNPC(i)->getAvatar());
        QString fileSuffix = fileInfo.suffix();
        QString tmpPath = normalNpcPath + this->getNormalNPC(i)->getName() + "." + fileSuffix;
        QFile::copy(this->getNormalNPC(i)->getAvatar(),tmpPath);
    }
}
void Script::scriptSaveAllXml(QString path){
    QString fileName = path + this->getName() +"Index.xml";
    QFile xmlFile(fileName);
    xmlFile.open(QIODevice::WriteOnly);
    QXmlStreamWriter indexWriter(&xmlFile);
    indexWriter.setAutoFormatting(true);
    indexWriter.writeStartDocument();
/*              以下缩进对应xml文件中的从属关系                                                    */
    indexWriter.writeStartElement("index");
    indexWriter.writeTextElement("summary",Script::getSummary());
    indexWriter.writeTextElement("annoucement",Script::getAnnouncement());
/*          完成地图的路径标记                                                                   */
    indexWriter.writeStartElement("maps");
        QString mapPath = path + "/maps/";
        for(int i = 0; i < this->maps.size(); i++){
            QFileInfo fileInfo(this->getMap(i)->getPicFile());
            QString fileSuffix = fileInfo.suffix();
            QString tmpPath = mapPath + this->getMap(i)->getName() + "." + fileSuffix;
            indexWriter.writeStartElement(this->getMap(i)->getName());
                indexWriter.writeTextElement("summary",Script::getMap(i)->getIntroduction());
                indexWriter.writeTextElement("path",tmpPath);
            indexWriter.writeEndElement();
        }
     indexWriter.writeEndElement();
     /*          完成地图的路径标记                           */
     /*          进行普通场景的写入                               */
     indexWriter.writeStartElement("normalScenes");
        QString scenePath = path + "/normalScenes/";
        for(int i = 0; i < this->normalScene.size(); i++){
            QString tmpPath = scenePath + this->getNormalScene(i)->getName();   //这是一个文件夹
            indexWriter.writeTextElement("introduction",this->getNormalScene(i)->getIntro());
            indexWriter.writeStartElement("pics");
            QString counter = "1";
            for(int j = 0; j < this->getNormalScene(i)->getPicInfo()->size(); j++){
                indexWriter.writeTextElement("summary of pic" + counter,this->getNormalScene(i)->getPicInfo()->at(j));
                QFileInfo fileInfo(this->getNormalScene(i)->getPics()->at(j));
                QString fileSuffix = fileInfo.suffix();
                QString tmpPath2 = tmpPath + "/pic" + counter + "." + fileSuffix;
                indexWriter.writeTextElement("path of pic"+counter,tmpPath2);
                counter = counter + 1;
            }
            indexWriter.writeEndElement();
            indexWriter.writeStartElement("musics");
            counter = "1";
            for(int j = 0; j < this->getNormalScene(i)->getMusicInfo()->size(); j++){
                indexWriter.writeTextElement("summary of music"+counter,this->getNormalScene(i)->getMusicInfo()->at(j));
                QFileInfo fileInfo(this->getNormalScene(i)->getMusics()->at(j));
                QString fileSuffix = fileInfo.suffix();
                QString tmpPath2 = tmpPath + "/music" + counter + "." + fileSuffix;
                indexWriter.writeTextElement("path of music"+counter,tmpPath2);
                counter = counter + 1;
            }
            indexWriter.writeEndElement();
        }
     indexWriter.writeEndElement();
     /*          进行普通场景的写入                               */
     /*          进行战斗场景的写入                               */
     indexWriter.writeStartElement("battleScenes");
        QString battleScenePath = path + "/battleScenes/";
        for(int i = 0; i < this->normalScene.size(); i++){
            QString tmpPath = battleScenePath + this->getBattleScene(i)->getName();   //这是一个文件夹
            indexWriter.writeTextElement("introduction",this->getBattleScene(i)->getIntro());
            indexWriter.writeStartElement("pics");
            QString counter = "1";
            for(int j = 0; j < this->getBattleScene(i)->getPicInfo()->size(); j++){
                indexWriter.writeTextElement("summary of pic"+counter,this->getBattleScene(i)->getPicInfo()->at(j));
                QFileInfo fileInfo(this->getBattleScene(i)->getPics()->at(j));
                QString fileSuffix = fileInfo.suffix();
                QString tmpPath2 = tmpPath + "/pic" + counter + "." + fileSuffix;
                indexWriter.writeTextElement("path of pic"+counter,tmpPath2);
                counter = counter + 1;
            }
            indexWriter.writeEndElement();
            indexWriter.writeStartElement("musics");
            counter = "1";
            for(int j = 0; j < this->getBattleScene(i)->getMusicInfo()->size(); j++){
                indexWriter.writeTextElement("summary of music"+counter,this->getBattleScene(i)->getMusicInfo()->at(j));
                QFileInfo fileInfo(this->getBattleScene(i)->getPics()->at(j));
                QString fileSuffix = fileInfo.suffix();
                QString tmpPath2 = tmpPath + "/music" + counter + "." + fileSuffix;
                indexWriter.writeTextElement("path of music"+counter,tmpPath2);
                counter = counter + 1;
            }
            indexWriter.writeEndElement();
        }
     indexWriter.writeEndElement();
     /*          进行战斗场景的写入                               */
     indexWriter.writeStartElement("keyNpc");
     QString keyNpcPath = path + "/keyNpc/";
        for(int i = 0; i < this->keyNpc.size(); i++){
            indexWriter.writeStartElement(this->getKeyNPC(i)->getName());
                //人物信息的记录完成
                indexWriter.writeTextElement("sex",QString::number(this->getKeyNPC(i)->getSex()));
                indexWriter.writeTextElement("age",QString::number(this->getKeyNPC(i)->getAge(),10));
                indexWriter.writeTextElement("information",this->getKeyNPC(i)->getRenWuMiaoShu());
                QFileInfo fileInfo(this->getKeyNPC(i)->getAvatar());
                QString fileSuffix = fileInfo.suffix();
                QString tmpPath = keyNpcPath + this->getKeyNPC(i)->getName() + "." + fileSuffix;
                indexWriter.writeTextElement("pathOfPhoto",tmpPath);
                indexWriter.writeTextElement("job",QString::number(this->getKeyNPC(i)->getJob()));
                indexWriter.writeTextElement("preciousThing",this->getKeyNPC(i)->getBaoGuiZhiWu());
                indexWriter.writeTextElement("bornArea",this->getKeyNPC(i)->getBornArea());
                indexWriter.writeTextElement("fearAndFanaticism",this->getKeyNPC(i)->getKongJu_kuangRe());
                indexWriter.writeTextElement("traumas",this->getKeyNPC(i)->getChuangShang_BaHen());
                indexWriter.writeTextElement("closeEncounters",this->getKeyNPC(i)->getDiSanLeiJieChu());
                indexWriter.writeTextElement("liveArea",this->getKeyNPC(i)->getLiveArea());
                indexWriter.writeTextElement("details",this->getKeyNPC(i)->getRenWuMiaoShu());
                indexWriter.writeTextElement("class",QString::number(this->getKeyNPC(i)->getShengHuoShuiPing()));
                indexWriter.writeTextElement("paternoster",this->getKeyNPC(i)->getShenMiJuanZhou_ZhouWen_GuWenWu());
                indexWriter.writeTextElement("belief",this->getKeyNPC(i)->getSiNian_xinNian());
                indexWriter.writeTextElement("characteristic",this->getKeyNPC(i)->getTeDian());
                indexWriter.writeTextElement("Tools",this->getKeyNPC(i)->getXieDaiWuPin());
                indexWriter.writeTextElement("significantPlace",this->getKeyNPC(i)->getYiYiFeiFanZhiDi());
                indexWriter.writeTextElement("significantOther",this->getKeyNPC(i)->getZhongYaoZhiRen());
                //记录人物属性
                indexWriter.writeStartElement("weapons");
                for(int k = 0; k < 4; k++){
                    indexWriter.writeStartElement(this->getKeyNPC(i)->getWeapon(k).weapon);
                    indexWriter.writeTextElement("ammo",QString::number(this->getKeyNPC(i)->getWeapon(k).ammo));
                    indexWriter.writeTextElement("damage",QString::number(this->getKeyNPC(i)->getWeapon(k).damage));
                    indexWriter.writeTextElement("difficulty",QString::number(this->getKeyNPC(i)->getWeapon(k).difficulty));
                    indexWriter.writeTextElement("range",QString::number(this->getKeyNPC(i)->getWeapon(k).range));
                    indexWriter.writeTextElement("times",QString::number(this->getKeyNPC(i)->getWeapon(k).times));
                    indexWriter.writeTextElement("mulfunction",this->getKeyNPC(i)->getWeapon(k).mulfunction);
                    indexWriter.writeEndElement();
                }
                indexWriter.writeEndElement();
                indexWriter.writeStartElement("skills");
                for(int k = 0; k < this->getKeyNPC(i)->skillNum; k++){
                    indexWriter.writeTextElement(this->getKeyNPC(i)->skillNames.at(k),QString::number(this->getKeyNPC(i)->getSkill((KeyNpc::eSkill)k)));
                }
                indexWriter.writeEndElement();
                indexWriter.writeStartElement("Attributes");
                for(int k = 0; k < this->getKeyNPC(i)->attributeNum; k++){
                    indexWriter.writeTextElement(this->getKeyNPC(i)->attributeNames.at(k),QString::number(this->getKeyNPC(i)->getAttribute((KeyNpc::eAttribute)k)));
                }
                indexWriter.writeEndElement();
            indexWriter.writeEndElement();
        }
    indexWriter.writeEndElement();
    //记录普通npc
    indexWriter.writeStartElement("normalNpc");
    QString normalNpcPath = path + "/normalNpc/";
        for(int i = 0; i < this->normalNpc.size(); i++){
            indexWriter.writeStartElement(this->getNormalNPC(i)->getName());
            QFileInfo fileInfo(this->getNormalNPC(i)->getAvatar());
            QString fileSuffix = fileInfo.suffix();
            QString tmpPath = normalNpcPath + this->getNormalNPC(i)->getName() + "." + fileSuffix;
                indexWriter.writeTextElement("age",QString::number(this->getNormalNPC(i)->getAge()));
                indexWriter.writeTextElement("sex",QString::number(this->getNormalNPC(i)->getSex()));
                indexWriter.writeTextElement("information",this->getNormalNPC(i)->getGeRenXinXi());
                indexWriter.writeTextElement("avatar",tmpPath);
            indexWriter.writeEndElement();
        }
    indexWriter.writeEndElement();
    indexWriter.writeEndElement();
}

} // namespace ptzs
