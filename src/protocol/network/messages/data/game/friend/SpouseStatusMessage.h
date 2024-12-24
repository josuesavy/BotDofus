#ifndef SPOUSESTATUSMESSAGE_H
#define SPOUSESTATUSMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class SpouseStatusMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SpouseStatusMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SpouseStatusMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SpouseStatusMessage(FuncTree tree);
  SpouseStatusMessage();

  bool hasSpouse;

private:
  void _hasSpouseFunc(Reader *input);
};

#endif // SPOUSESTATUSMESSAGE_H