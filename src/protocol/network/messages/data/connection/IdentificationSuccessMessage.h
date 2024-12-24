#ifndef IDENTIFICATIONSUCCESSMESSAGE_H
#define IDENTIFICATIONSUCCESSMESSAGE_H

#include "src/protocol/network/types/data/common/AccountTagInformation.h"
#include "src/utils/io/type/BooleanByteWrapper.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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
  AccountTagInformation accountTag;
  uint accountId;
  uint communityId;
  bool hasRights;
  bool hasReportRight;
  bool hasForceRight;
  double accountCreation;
  double subscriptionEndDate;
  bool wasAlreadyConnected;
  uint havenbagAvailableRoom;

private:
  void deserializeByteBoxes(Reader *input);
  void _loginFunc(Reader *input);
  void _accountTagtreeFunc(Reader *input);
  void _accountIdFunc(Reader *input);
  void _communityIdFunc(Reader *input);
  void _accountCreationFunc(Reader *input);
  void _subscriptionEndDateFunc(Reader *input);
  void _havenbagAvailableRoomFunc(Reader *input);

  FuncTree _accountTagtree;
};

#endif // IDENTIFICATIONSUCCESSMESSAGE_H