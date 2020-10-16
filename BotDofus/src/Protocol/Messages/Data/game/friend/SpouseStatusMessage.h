#ifndef SPOUSESTATUSMESSAGE_H
#define SPOUSESTATUSMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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