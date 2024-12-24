#ifndef OBJECTAVERAGEPRICESMESSAGE_H
#define OBJECTAVERAGEPRICESMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ObjectAveragePricesMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectAveragePricesMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectAveragePricesMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectAveragePricesMessage(FuncTree tree);
  ObjectAveragePricesMessage();

  QList<uint> ids;
  QList<double> avgPrices;

private:
  void _idstreeFunc(Reader *input);
  void _idsFunc(Reader *input);
  void _avgPricestreeFunc(Reader *input);
  void _avgPricesFunc(Reader *input);

  FuncTree _idstree;
  FuncTree _avgPricestree;
};

#endif // OBJECTAVERAGEPRICESMESSAGE_H