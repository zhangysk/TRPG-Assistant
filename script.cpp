#include "script.h"

namespace ptzs {

Script::Script()
{
}

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
            QFileInfo fileInfo(this->getBattleScene(i)->getPics(j));
            QString fileSuffix = fileInfo.suffix();
            QString tmpPath2 = tmpPath + "/pic" + counter + "." + fileSuffix;
            QFile::copy(this->getBattleScene(i)->getPics(j),tmpPath2);
        }
        for(int j = 0; j < this->getBattleScene(i)->musicNum(); j++){
            QFileInfo fileInfo(this->getBattleScene(i)->getPics(j));
            QString fileSuffix = fileInfo.suffix();
            QString tmpPath2 = tmpPath + "/music" + counter + "." + fileSuffix;
            QFile::copy(this->getBattleScene(i)->getPics(j),tmpPath2);
        }
    }
    for(int i = 0; i < this->normalScene.size(); i++){
        QString tmpPath = normalScenesPath + this->getNormalScene(i)->getName();
        for(int j = 0; j < this->getNormalScene(i)->picNum(); j++){
            QFileInfo fileInfo(this->getNormalScene(i)->getPics(j));
            QString fileSuffix = fileInfo.suffix();
            QString tmpPath2 = tmpPath + "/pic" + counter + "." + fileSuffix;
            QFile::copy(this->getNormalScene(i)->getPics(j),tmpPath2);
        }
        for(int j = 0; j < this->getNormalScene(i)->musicNum(); j++){
            QFileInfo fileInfo(this->getNormalScene(i)->getPics(j));
            QString fileSuffix = fileInfo.suffix();
            QString tmpPath2 = tmpPath + "/music" + counter + "." + fileSuffix;
            QFile::copy(this->getNormalScene(i)->getPics(j),tmpPath2);
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
            for(int j = 0; j < this->getNormalScene(i)->picNum(); j++){
                indexWriter.writeTextElement("summary of pic" + counter,this->getNormalScene(i)->getPicInfo(j));
                QFileInfo fileInfo(this->getNormalScene(i)->getPics(j));
                QString fileSuffix = fileInfo.suffix();
                QString tmpPath2 = tmpPath + "/pic" + counter + "." + fileSuffix;
                indexWriter.writeTextElement("path of pic"+counter,tmpPath2);
                counter = counter + 1;
            }
            indexWriter.writeEndElement();
            indexWriter.writeStartElement("musics");
            counter = "1";
            for(int j = 0; j < this->getNormalScene(i)->musicNum(); j++){
                indexWriter.writeTextElement("summary of music"+counter,this->getNormalScene(i)->getMusicInfo(j));
                QFileInfo fileInfo(this->getNormalScene(i)->getMusics(j));
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
            for(int j = 0; j < this->getBattleScene(i)->picNum(); j++){
                indexWriter.writeTextElement("summary of pic"+counter,this->getBattleScene(i)->getPicInfo(j));
                QFileInfo fileInfo(this->getBattleScene(i)->getPics(j));
                QString fileSuffix = fileInfo.suffix();
                QString tmpPath2 = tmpPath + "/pic" + counter + "." + fileSuffix;
                indexWriter.writeTextElement("path of pic"+counter,tmpPath2);
                counter = counter + 1;
            }
            indexWriter.writeEndElement();
            indexWriter.writeStartElement("musics");
            counter = "1";
            for(int j = 0; j < this->getBattleScene(i)->musicNum(); j++){
                indexWriter.writeTextElement("summary of music"+counter,this->getBattleScene(i)->getMusicInfo(j));
                QFileInfo fileInfo(this->getBattleScene(i)->getPics(j));
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
void Script::scriptReadAll(QString path){
    QFile xmlFile(path);
    if(!xmlFile.open(QFile::ReadOnly)){
        return;
    }

    QDomDocument doc;
    if(!doc.setContent(&xmlFile)){
        xmlFile.close();
        return;
    }
    xmlFile.close();

    QDomElement root = doc.documentElement();
    QDomNode node = root.firstChild();
    int tmpMapNum;
    int tmpKeyNpcNum;
    int tmpNormalNpcNum;
    int tmpNormalSceneNum;
    int tmpBattleSceneNum;
    while(!node.isNull()){
        if(node.nodeName() == "index"){
            QDomElement s = node.toElement();
            QDomNodeList tmpNode = s.childNodes();
            for(int k = 0; k < tmpNode.size(); k++){
                if(tmpNode.at(k).nodeName() == "summary"){
                    this->setSummary(tmpNode.at(k).nodeValue());
                }
                else if(tmpNode.at(k).nodeName() == "announcement"){
                    this->setAnnouncement(tmpNode.at(k).nodeValue());
                }
                else if(tmpNode.at(k).nodeName() == "numOfMaps"){
                    tmpMapNum = tmpNode.at(k).nodeValue().toInt();
                }
                else if(tmpNode.at(k).nodeName() == "numOfKeyNpc"){
                    tmpKeyNpcNum = tmpNode.at(k).nodeValue().toInt();
                }
                else if(tmpNode.at(k).nodeName() == "numOfNormalNpc"){
                    tmpNormalNpcNum = tmpNode.at(k).nodeValue().toInt();
                }
                else if(tmpNode.at(k).nodeName() == "numOfNormalScene"){
                    tmpNormalSceneNum = tmpNode.at(k).nodeValue().toInt();
                }
                else if(tmpNode.at(k).nodeName() == "numOfBattleScene"){
                    tmpBattleSceneNum = tmpNode.at(k).nodeValue().toInt();
                }
                else if(tmpNode.at(k).nodeName() == "maps"){
                    QDomElement g = tmpNode.at(k).toElement();
                    QDomNodeList mapNode = g.childNodes();
                    for(int i = 0; i < tmpMapNum; i++){
                        this->addMap();
                        this->getMap(i)->setName(mapNode.at(i).nodeName());
                        QDomElement z = mapNode.at(i).toElement();
                        QDomNodeList tmpInfo = z.childNodes();
                        for(int j = 0; j < tmpInfo.size(); j++){
                            if(tmpInfo.at(j).nodeName() == "summary"){
                                this->getMap(i)->setIntroduction(tmpInfo.at(j).nodeValue());
                            }
                            else if(tmpInfo.at(j).nodeName() == "path"){
                                this->getMap(i)->setPicFile(tmpInfo.at(j).nodeValue());
                            }
                        }
                    }
                }
                else if(tmpNode.at(k).nodeName() == "normalNpc"){
                    QDomElement g = tmpNode.at(k).toElement();
                    QDomNodeList normalNpcNode = g.childNodes();
                    for(int i = 0; i < tmpNormalNpcNum; i++){
                        this->addNormalNPC();
                        this->getNormalNPC(i)->setName(normalNpcNode.at(i).nodeName());
                        QDomElement z = normalNpcNode.at(i).toElement();
                        QDomNodeList tmpInfo = z.childNodes();
                        for(int j = 0; j < tmpInfo.size(); j++){
                            if(tmpInfo.at(j).nodeName() == "age"){
                                this->getNormalNPC(i)->setAge(tmpInfo.at(j).nodeValue().toInt());
                            }
                            else if(tmpInfo.at(j).nodeName() == "sex"){
                                this->getNormalNPC(i)->setSex((KeyNpc::esex)tmpInfo.at(j).nodeValue().toInt());
                            }
                            else if(tmpInfo.at(j).nodeName() == "information"){
                                this->getNormalNPC(i)->setGeRenXinXi(tmpInfo.at(j).nodeValue());
                            }
                            else if(tmpInfo.at(j).nodeName() == "avatar"){
                                this->getNormalNPC(i)->setAvatar(tmpInfo.at(j).nodeValue());
                            }
                        }
                    }
                }
                else if(tmpNode.at(k).nodeName() == "keyNpc"){
                    QDomElement g = tmpNode.at(k).toElement();
                    QDomNodeList keyNpcNode = g.childNodes();
                    for(int i = 0; i < tmpKeyNpcNum; i++){
                        this->getKeyNPC(i)->setName(keyNpcNode.at(i).nodeName());
                        QDomElement z = keyNpcNode.at(i).toElement();
                        QDomNodeList tmpInfo = z.childNodes();
                        for(int j = 0; j < tmpInfo.size(); j++){
                            QDomNode tmpSave = tmpInfo.at(j);
                            if(tmpInfo.at(j).nodeName() == "sex"){
                                this->getKeyNPC(i)->setSex((KeyNpc::esex)tmpInfo.at(j).nodeValue().toInt());
                            }
                            else if(tmpSave.nodeName() == "age"){
                                this->getKeyNPC(i)->setAge(tmpInfo.at(j).nodeValue().toInt());
                            }
                            else if(tmpSave.nodeName() == "information"){
                                this->getKeyNPC(i)->setRenWuMiaoShu(tmpSave.nodeValue());
                            }
                            else if(tmpSave.nodeName() == "pathOfPhoto"){
                                this->getKeyNPC(i)->setAvatar(tmpSave.nodeValue());
                            }
                            else if(tmpSave.nodeName() == "job"){
                                this->getKeyNPC(i)->setJob((KeyNpc::eJob)tmpSave.nodeValue().toInt());
                            }
                            else if(tmpSave.nodeName() == "preciousThing"){
                                this->getKeyNPC(i)->setBaoGuiZhiWu(tmpSave.nodeValue());
                            }
                            else if(tmpSave.nodeName() == "bornArea"){
                                this->getKeyNPC(i)->setBornArea(tmpSave.nodeValue());
                            }
                            else if(tmpSave.nodeName() == "fearAndFantacism"){
                                this->getKeyNPC(i)->setKongJu_kuangRe(tmpSave.nodeValue());
                            }
                            else if(tmpSave.nodeName() == "traumas"){
                                this->getKeyNPC(i)->setChuangShang_BaHen(tmpSave.nodeValue());
                            }
                            else if(tmpSave.nodeName() == "closeEncounters"){
                                this->getKeyNPC(i)->setDiSanLeiJieChu(tmpSave.nodeValue());
                            }
                            else if(tmpSave.nodeName() == "livaArea"){
                                this->getKeyNPC(i)->setLiveArea(tmpSave.nodeValue());
                            }
                            else if(tmpSave.nodeName() == "class"){
                                this->getKeyNPC(i)->setShengHuoShuiPing((KeyNpc::eLivingStantard)tmpSave.nodeValue().toInt());
                            }
                            else if(tmpSave.nodeName() == "paternoster"){
                                this->getKeyNPC(i)->setShenMiJuanZhou_ZhouWen_GuWenWu(tmpSave.nodeValue());
                            }
                            else if(tmpSave.nodeName() == "belief"){
                                this->getKeyNPC(i)->setSiNian_xinNian(tmpSave.nodeValue());
                            }
                            else if(tmpSave.nodeName() == "characteristic"){
                                this->getKeyNPC(i)->setTeDian(tmpSave.nodeValue());
                            }
                            else if(tmpSave.nodeName() == "Tools"){
                                this->getKeyNPC(i)->setXieDaiWuPin(tmpSave.nodeValue());
                            }
                            else if(tmpSave.nodeName() == "significantPlace"){
                                this->getKeyNPC(i)->setYiYiFeiFanZhiDi(tmpSave.nodeValue());
                            }
                            else if(tmpSave.nodeName() == "significantOther"){
                                this->getKeyNPC(i)->setZhongYaoZhiRen(tmpSave.nodeValue());
                            }
                            else if(tmpSave.nodeName() == "weapons"){
                                QDomElement g = tmpSave.toElement();
                                QDomNodeList weaponNode = g.childNodes();
                                for(int q = 0; q < 4; q++){
                                    KeyNpc::sWeapon tmpWeapon;
                                    tmpWeapon.weapon = weaponNode.at(q).nodeName();
                                    QDomElement z = weaponNode.at(q).toElement();
                                    QDomNodeList tmpWeaponInfo = z.childNodes();
                                    for(int l = 0; l < tmpWeaponInfo.size(); l++){
                                        if(tmpWeaponInfo.at(l).nodeName() == "ammo"){
                                            tmpWeapon.ammo = tmpWeaponInfo.at(l).nodeValue().toInt();
                                        }
                                        else if(tmpWeaponInfo.at(l).nodeName() == "damage"){
                                            tmpWeapon.damage = tmpWeaponInfo.at(l).nodeValue().toInt();
                                        }
                                        else if(tmpWeaponInfo.at(l).nodeName() == "difficulty"){
                                            tmpWeapon.difficulty = tmpWeaponInfo.at(l).nodeValue().toInt();
                                        }
                                        else if(tmpWeaponInfo.at(l).nodeName() == "range"){
                                            tmpWeapon.range = tmpWeaponInfo.at(l).nodeValue().toInt();
                                        }
                                        else if(tmpWeaponInfo.at(l).nodeName() == "times"){
                                            tmpWeapon.times = tmpWeaponInfo.at(l).nodeValue().toInt();
                                        }
                                        else if(tmpWeaponInfo.at(l).nodeName() == "mulfucntion"){
                                            tmpWeapon.mulfunction = tmpWeaponInfo.at(l).nodeValue();
                                        }
                                    }
                                    this->getKeyNPC(i)->setWeapon(q,tmpWeapon);
                                }
                            }
                            else if(tmpSave.nodeName() == "skills"){
                                QDomElement g = tmpSave.toElement();
                                QDomNodeList skillInfo = g.childNodes();
                                for(int q = 0; q < KeyNpc::skillNum; q++){
                                    this->getKeyNPC(i)->setSkill((KeyNpc::eSkill)q,skillInfo.at(q).nodeValue().toInt());
                                }
                            }
                            else if(tmpSave.nodeName() == "Attributes"){
                                QDomElement g = tmpSave.toElement();
                                QDomNodeList attributeInfo = g.childNodes();
                                for(int q = 0; q < KeyNpc::attributeNum; q++){
                                    this->getKeyNPC(i)->setAttribute((KeyNpc::eAttribute)q,attributeInfo.at(q).nodeValue().toInt());
                                }
                            }
                        }
                    }
                }
            }
        }
        node = node.nextSibling();
    }
}
} // namespace ptzs
