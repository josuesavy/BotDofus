#ifndef SOCIALAPPLICATIONINFORMATION_H
#define SOCIALAPPLICATIONINFORMATION_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/social/application/ApplicationPlayerInformation.h"
#include "src/utils/io/type/FuncTree.h"

class SocialApplicationInformation : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SocialApplicationInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SocialApplicationInformation(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SocialApplicationInformation(FuncTree tree);
  SocialApplicationInformation();
  bool operator==(const SocialApplicationInformation &compared);

  QSharedPointer<ApplicationPlayerInformation> playerInfo;
  QString applyText;
  double creationDate;

private:
  void _playerInfotreeFunc(Reader *input);
  void _applyTextFunc(Reader *input);
  void _creationDateFunc(Reader *input);

  FuncTree _playerInfotree;
};

#endif // SOCIALAPPLICATIONINFORMATION_H