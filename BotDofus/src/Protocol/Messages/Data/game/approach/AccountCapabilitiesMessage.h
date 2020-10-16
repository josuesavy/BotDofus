#ifndef ACCOUNTCAPABILITIESMESSAGE_H
#define ACCOUNTCAPABILITIESMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Engines/IO/Network/Utils/BooleanByteWrapper.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class AccountCapabilitiesMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AccountCapabilitiesMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AccountCapabilitiesMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AccountCapabilitiesMessage(FuncTree tree);
  AccountCapabilitiesMessage();

  uint accountId;
  bool tutorialAvailable;
  uint breedsVisible;
  uint breedsAvailable;
  int status;
  bool canCreateNewCharacter;

private:
  void deserializeByteBoxes(Reader *input);
  void _accountIdFunc(Reader *input);
  void _breedsVisibleFunc(Reader *input);
  void _breedsAvailableFunc(Reader *input);
  void _statusFunc(Reader *input);
};

#endif // ACCOUNTCAPABILITIESMESSAGE_H