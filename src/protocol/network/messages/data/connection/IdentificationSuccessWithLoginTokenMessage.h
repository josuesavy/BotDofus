#ifndef IDENTIFICATIONSUCCESSWITHLOGINTOKENMESSAGE_H
#define IDENTIFICATIONSUCCESSWITHLOGINTOKENMESSAGE_H

#include "src/protocol/network/types/data/common/AccountTagInformation.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/connection/IdentificationSuccessMessage.h"

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