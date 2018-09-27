#ifndef FILESAVER_H
#define FILESAVER_H

#include <QString>
#include <QFileInfo>

namespace ptzs {

//假设这里接收到的内容是：1.音乐的path	2.文字描述都有具体的描述	3.图片的path
//我要做的工作：	1.提供播放音乐的函数				ok
//					2.提供显示图片的函数
//					3.转存这些文字、图片和音乐，点击时saveAll到指定路径,按照文件夹顺序，并不需要考虑单独存这些情况,并假设已知文件夹路径
//					4.上述路径都是QSting
//					5.给文字这些内容标注文件名，并转存到各自文件夹中

/*								volume是1-100之间的值，path是音乐文件的绝对路径。			*/
/*								这个函数用来播放音乐，加到合适的地方						*/
void mediaPlay(QString path,int volume){
    QMediaPlayer *myPlay = new QMediaPlayer;
    myPlayer->setMedia(QUrl::fromLocalFile(path));
    myPlay->setVolume(volume);
    myPlay->play();
}

void Scropt::saveAll(QString path){
//					首先创建整体文件夹，保留外部路径
//					对于文件下每个部分的路径延长字符串，之后进行存储

}

class FileSaver
{
public:
    FileSaver();
};

} // namespace ptzs

#endif // FILESAVER_H
