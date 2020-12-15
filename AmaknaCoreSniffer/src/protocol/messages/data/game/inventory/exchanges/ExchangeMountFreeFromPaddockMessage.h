#ifndef EXCHANGEMOUNTFREEFROMPADDOCKMESSAGE_H
#define EXCHANGEMOUNTFREEFROMPADDOCKMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ExchangeMountFreeFromPaddockMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeMountFreeFromPaddockMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeMountFreeFromPaddockMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeMountFreeFromPaddockMessage(FuncTree tree);
  ExchangeMountFreeFromPaddockMessage();

  QString name;
  int worldX;
  int worldY;
  QString liberator;

private:
  void _nameFunc(Reader *input);
  void _worldXFunc(Reader *input);
  void _worldYFunc(Reader *input);
  void _liberatorFunc(Reader *input);
};

#endif // EXCHANGEMOUNTFREEFROMPADDOCKMESSAGE_H