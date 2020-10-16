#ifndef EXCHANGEMOUNTSTAKENFROMPADDOCKMESSAGE_H
#define EXCHANGEMOUNTSTAKENFROMPADDOCKMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ExchangeMountsTakenFromPaddockMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeMountsTakenFromPaddockMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeMountsTakenFromPaddockMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeMountsTakenFromPaddockMessage(FuncTree tree);
  ExchangeMountsTakenFromPaddockMessage();

  QString name;
  int worldX;
  int worldY;
  QString ownername;

private:
  void _nameFunc(Reader *input);
  void _worldXFunc(Reader *input);
  void _worldYFunc(Reader *input);
  void _ownernameFunc(Reader *input);
};

#endif // EXCHANGEMOUNTSTAKENFROMPADDOCKMESSAGE_H