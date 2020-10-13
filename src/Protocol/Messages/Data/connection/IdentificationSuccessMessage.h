#ifndef IDENTIFICATIONSUCCESSMESSAGE_H
#define IDENTIFICATIONSUCCESSMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Engines/IO/Network/Utils/BooleanByteWrapper.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class IdentificationSuccessMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_IdentificationSuccessMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_IdentificationSuccessMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_IdentificationSuccessMessage(FuncTree tree);
  IdentificationSuccessMessage();

  QString login;
  QString nickname;
  uint accountId;
  uint communityId;
  bool hasRights;
  bool hasConsoleRight;
  QString secretQuestion;
  double accountCreation;
  double subscriptionElapsedDuration;
  double subscriptionEndDate;
  bool wasAlreadyConnected;
  uint havenbagAvailableRoom;

private:
  void deserializeByteBoxes(Reader *input);
  void _loginFunc(Reader *input);
  void _nicknameFunc(Reader *input);
  void _accountIdFunc(Reader *input);
  void _communityIdFunc(Reader *input);
  void _secretQuestionFunc(Reader *input);
  void _accountCreationFunc(Reader *input);
  void _subscriptionElapsedDurationFunc(Reader *input);
  void _subscriptionEndDateFunc(Reader *input);
  void _havenbagAvailableRoomFunc(Reader *input);
};

#endif // IDENTIFICATIONSUCCESSMESSAGE_H