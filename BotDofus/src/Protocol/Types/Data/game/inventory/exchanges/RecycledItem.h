#ifndef RECYCLEDITEM_H
#define RECYCLEDITEM_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class RecycledItem : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_RecycledItem(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_RecycledItem(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_RecycledItem(FuncTree tree);
  RecycledItem();
  bool operator==(const RecycledItem &compared);

  uint id;
  uint qty;

private:
  void _idFunc(Reader *input);
  void _qtyFunc(Reader *input);
};

#endif // RECYCLEDITEM_H