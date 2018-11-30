#include "TextureSection.h"

TextureSection::TextureSection(QWidget* parent) : QWidget(parent)
{
	this->group = std::make_unique<QWidget>();
}

TextureSection::~TextureSection()
{

}
