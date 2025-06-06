#pragma once

#include "CoreMinimal.h"
#include "..\AnimInstance_Character.h"
#include "Characters/Character_Player.h"
#include "AnimInstance_Player.generated.h"

/**
 * 
 */
UCLASS()
class ARPG_API UAnimInstance_Player : public UAnimInstance_Character
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="AnimData|References")
	ACharacter_Player* OwningCharacter_Player;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="AnimData|LocomotionData")
	bool bShouldEnterRelaxState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AnimData|LocomotionData")
	float EnterRelaxStateThreshold = 5.f;
	
	float IdleElapsedTime;
};
