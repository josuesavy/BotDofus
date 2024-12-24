#ifndef ITEMFORPRESET_H
#define ITEMFORPRESET_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/utils/io/type/FuncTree.h"

class ItemForPreset : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ItemForPreset(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ItemForPreset(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ItemForPreset(FuncTree tree);
  ItemForPreset();
  bool operator==(const ItemForPreset &compared);

  uint position;
  uint objGid;
  uint objUid;

private:
  void _positionFunc(Reader *input);
  void _objGidFunc(Reader *input);
  void _objUidFunc(Reader *input);
};

#endif // ITEMFORPRESET_H