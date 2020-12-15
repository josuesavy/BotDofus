#ifndef IDENTIFICATIONSUCCESSWITHLOGINTOKENMESSAGE_H
#define IDENTIFICATIONSUCCESSWITHLOGINTOKENMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/connection/IdentificationSuccessMessage.h"

class IdentificationSuccessWithLoginTokenMessage : public IdentificationSuccessMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_IdentificationSuccessWithLoginTokenMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_IdentificationSuccessWithLoginTokenMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_IdentificationSuccessWithLoginTokenMessage(FuncTree tree);
  IdentificationSuccessWithLoginTokenMessage();

  QString loginToken;

private:
  void _loginTokenFunc(Reader *input);
};

#endif // IDENTIFICATIONSUCCESSWITHLOGINTOKENMESSAGE_H