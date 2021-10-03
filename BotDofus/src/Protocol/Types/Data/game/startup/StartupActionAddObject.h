#ifndef STARTUPACTIONADDOBJECT_H
#define STARTUPACTIONADDOBJECT_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/data/items/ObjectItemInformationWithQuantity.h"
#include "src/engines/io/network/utils/FuncTree.h"

class StartupActionAddObject : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_StartupActionAddObject(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_StartupActionAddObject(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_StartupActionAddObject(FuncTree tree);
  StartupActionAddObject();
  bool operator==(const StartupActionAddObject &compared);

  uint uid;
  QString title;
  QString text;
  QString descUrl;
  QString pictureUrl;
  QList<QSharedPointer<ObjectItemInformationWithQuantity>> items;

private:
  void _uidFunc(Reader *input);
  void _titleFunc(Reader *input);
  void _textFunc(Reader *input);
  void _descUrlFunc(Reader *input);
  void _pictureUrlFunc(Reader *input);
  void _itemstreeFunc(Reader *input);
  void _itemsFunc(Reader *input);

  FuncTree _itemstree;
};

#endif // STARTUPACTIONADDOBJECT_H