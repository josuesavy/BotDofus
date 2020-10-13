#ifndef DECRAFTEDITEMSTACKINFO_H
#define DECRAFTEDITEMSTACKINFO_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class DecraftedItemStackInfo : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_DecraftedItemStackInfo(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_DecraftedItemStackInfo(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_DecraftedItemStackInfo(FuncTree tree);
  DecraftedItemStackInfo();
  bool operator==(const DecraftedItemStackInfo &compared);

  uint objectUID;
  double bonusMin;
  double bonusMax;
  QList<uint> runesId;
  QList<uint> runesQty;

private:
  void _objectUIDFunc(Reader *input);
  void _bonusMinFunc(Reader *input);
  void _bonusMaxFunc(Reader *input);
  void _runesIdtreeFunc(Reader *input);
  void _runesIdFunc(Reader *input);
  void _runesQtytreeFunc(Reader *input);
  void _runesQtyFunc(Reader *input);

  FuncTree _runesIdtree;
  FuncTree _runesQtytree;
};

#endif // DECRAFTEDITEMSTACKINFO_H