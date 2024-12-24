#ifndef BIDEXCHANGEROBJECTINFO_H
#define BIDEXCHANGEROBJECTINFO_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/data/items/effects/ObjectEffect.h"
#include "src/protocol/network/types/ClassManager.h"
#include "src/utils/io/type/FuncTree.h"

class BidExchangerObjectInfo : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BidExchangerObjectInfo(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BidExchangerObjectInfo(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BidExchangerObjectInfo(FuncTree tree);
  BidExchangerObjectInfo();
  bool operator==(const BidExchangerObjectInfo &compared);

  uint objectUID;
  uint objectGID;
  uint objectType;
  QList<QSharedPointer<ObjectEffect>> effects;
  QList<double> prices;

private:
  void _objectUIDFunc(Reader *input);
  void _objectGIDFunc(Reader *input);
  void _objectTypeFunc(Reader *input);
  void _effectstreeFunc(Reader *input);
  void _effectsFunc(Reader *input);
  void _pricestreeFunc(Reader *input);
  void _pricesFunc(Reader *input);

  FuncTree _effectstree;
  FuncTree _pricestree;
};

#endif // BIDEXCHANGEROBJECTINFO_H