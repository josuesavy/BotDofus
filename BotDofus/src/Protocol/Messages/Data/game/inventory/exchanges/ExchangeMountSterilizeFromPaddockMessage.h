#ifndef EXCHANGEMOUNTSTERILIZEFROMPADDOCKMESSAGE_H
#define EXCHANGEMOUNTSTERILIZEFROMPADDOCKMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ExchangeMountSterilizeFromPaddockMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeMountSterilizeFromPaddockMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeMountSterilizeFromPaddockMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeMountSterilizeFromPaddockMessage(FuncTree tree);
  ExchangeMountSterilizeFromPaddockMessage();

  QString name;
  int worldX;
  int worldY;
  QString sterilizator;

private:
  void _nameFunc(Reader *input);
  void _worldXFunc(Reader *input);
  void _worldYFunc(Reader *input);
  void _sterilizatorFunc(Reader *input);
};

#endif // EXCHANGEMOUNTSTERILIZEFROMPADDOCKMESSAGE_H