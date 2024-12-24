#ifndef GAMEACTIONITEM_H
#define GAMEACTIONITEM_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/data/items/ObjectItemInformationWithQuantity.h"
#include "src/utils/io/type/FuncTree.h"

class GameActionItem : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionItem(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionItem(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionItem(FuncTree tree);
  GameActionItem();
  bool operator==(const GameActionItem &compared);

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

#endif // GAMEACTIONITEM_H