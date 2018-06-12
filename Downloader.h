#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QFile>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QObject>
#include <QUrl>
#include <QFile>

class Downloader : public QObject
{
    Q_OBJECT
    public:
        explicit Downloader(QObject *parent = 0);
        virtual ~Downloader();

        void downloadFileFromURL(const QString &url, const QString &filePath);
        bool ckeck_pic();

    private slots:
        void onDownloadFileComplete(QNetworkReply *reply);

    private:
        QFile *         m_file;
        bool            m_isReady = true;
        QString         m_filePath;
};

#endif // DOWNLOADER_H
