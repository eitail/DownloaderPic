#include "Downloader.h"
#include <QDebug>
#include <QEventLoop>

Downloader::Downloader(QObject *parent) : QObject(parent)
{

}

Downloader::~Downloader()
{

}

/***********************************************
 * 下载图片保存图片
 * *********************************************/
void Downloader::downloadFileFromURL(const QString &url, const QString &filePath)
{
    if (!m_isReady)
        return;

    m_isReady = false;
    m_filePath = filePath;
    qDebug() << filePath;
    m_file = new QFile();
    m_file->setFileName(filePath);
    m_file->open(QIODevice::WriteOnly);

    if (!m_file->isOpen()) {
       m_isReady = true;
        return;
    }

    QNetworkAccessManager *manager = new QNetworkAccessManager;

    QNetworkRequest request;
    request.setUrl(QUrl(url));

   connect(manager, SIGNAL(finished(QNetworkReply *)), this, SLOT(onDownloadFileComplete(QNetworkReply *)));

   manager->get(request);
}

/***********************************************
 * 槽函数保存图片
 * *********************************************/
void Downloader::onDownloadFileComplete(QNetworkReply *reply)
{
    if (!m_file->isWritable()) {
        m_isReady = true;
        return;
    }
    QByteArray pic = reply->readAll();
    m_file->write(pic);
    m_file->close();
    ckeck_pic();
    m_isReady = true;
}

/***********************************************
 * 检测图片完整性
 * *********************************************/
bool Downloader::ckeck_pic()
{
    qDebug() << "=================================";
    bool is_complete = false;

    QFile file(m_filePath);
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"Can't open the file!"<<endl;
    }

    while(!file.atEnd())
    {
        QByteArray line = file.readLine();
            bool b = line.contains("\xff\xd9");
            if(b)
            {
                is_complete = true;
            }
    }

    //------ 检测打印 ------
    if(is_complete)
    {
        qDebug() << "ok-2-";
    }
    else
    {
        qDebug() << "err-1-";
    }

    file.close();
    qDebug() << "=================================";
    return is_complete;
}
