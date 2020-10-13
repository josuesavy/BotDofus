#ifndef IDENTIFICATIONSUCCESSWITHLOGINTOKENMESSAGE_H
#define IDENTIFICATIONSUCCESSWITHLOGINTOKENMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/connection/IdentificationSuccessMessage.h"

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