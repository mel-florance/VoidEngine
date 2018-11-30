#pragma once

#include <QMap>
#include <QImage>
#include <QSharedPointer>

class ImagesManager
{
public:
	ImagesManager();
	~ImagesManager();

	static inline void loadImage(const QString& path) {
		ImagesManager::images[path] = QSharedPointer<QImage>::create(path);
	}

	static QMap<QString, QSharedPointer<QImage>> images;
};

