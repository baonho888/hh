-- ORION LIB
local OrionLib = loadstring(game:HttpGet("https://raw.githubusercontent.com/duysira5/Hehe/refs/heads/main/Orion.lua.txt"))()

local Players = game:GetService("Players")
local RunService = game:GetService("RunService")
local TweenService = game:GetService("TweenService")
local LP = Players.LocalPlayer

--================ WINDOW =================
local Window = OrionLib:MakeWindow({
    Name = "Tét Hụb",
    SaveConfig = true,
    ConfigFolder = "FakeHub"
})

local Tab = Window:MakeTab({
    Name = "Main",
    Icon = "rbxassetid://4483345998"
})
local Tab2 = Window:MakeTab({
    Name = "LocalPlayer",
    Icon = "rbxassetid://4483345998"
})
local Tab3 = Window:MakeTab({
    Name = "World",
    Icon = "rbxassetid://4483345998"
})

-- Tạo Tab Teleport mới
local TabTele = Window:MakeTab({
    Name = "Teleport Island⭐",
    Icon = "rbxassetid://4483345998"
})

--// SERVICES
local lp = Players.LocalPlayer

--// GLOBAL
getgenv().AutoFarm = false
getgenv().SeaSelect = "Sea 1"

--// SEA 1 FULL
local Sea1Table = {
    {1,"Boss","Quest1"},
    {50,"SnowBoss","Quest2"},
    {100,"Sand","Quest3"},
    {250,"Enel","Quest4"},
    {550,"Ace","Quest5"},
    {900,"Minmama","Quest6"},
    {1350,"Dark","Quest7"},
}

--// SEA 2 FULL
local Sea2Table = {
    {2000,"Paw","Quest1"},
    {4000,"Magma Admiral","Quest2"},
    {8000,"Nickbeo","Quest3"},
    {16000,"Tango","Quest4"},
    {20000,"Garou","Quest5"},
    {50000,"Sukuna","Quest6"},
    {100000,"Grab","Quest7"},
    {500000,"Pride","Quest9"},
}

--// LEVEL
local function getLevel()
	local d = lp:FindFirstChild("Data")
	if d and d:FindFirstChild("Levels") then
		return d.Levels.Value
	end
	return 1
end

--// TARGET
local function getTarget()
	local level = getLevel()
	local tableUse = getgenv().SeaSelect == "Sea 1" and Sea1Table or Sea2Table
	local result = tableUse[1]

	for _,v in ipairs(tableUse) do
		if level >= v[1] then
			result = v
		else
			break
		end
	end

	return result[2], result[3]
end

--// FIND NPC
local function findBoss(name)
	local folder = workspace:FindFirstChild("NPC DAMAGE")
	if not folder then return end

	name = string.lower(name)

	for _,npc in pairs(folder:GetChildren()) do
		if string.find(string.lower(npc.Name), name) then
			return npc
		end
	end
end

--// QUEST SMART
local function doQuest(questName)
	local npcs = workspace:FindFirstChild("NPCS")
	if not npcs then return end

	local q = npcs:FindFirstChild(questName)
	if not q then return end

	local qt = q.ClickPart.QuestTake.QuestTake

	pcall(function()
		if getgenv().SeaSelect == "Sea 2" and qt:FindFirstChild("Accept3") then
			qt.Accept3.RemoteEvent:FireServer()
		elseif qt:FindFirstChild("Accept2") then
			qt.Accept2.RemoteEvent:FireServer()
		elseif qt:FindFirstChild("Accept1") then
			qt.Accept1.RemoteEvent:FireServer()
		end
	end)
end

--// TWEEN BEHIND
local function tweenBehind(boss)
	local char = lp.Character
	if not char then return end

	local hrp = char:FindFirstChild("HumanoidRootPart")
	local bhrp = boss and boss:FindFirstChild("HumanoidRootPart")

	if not hrp or not bhrp then return end

	local pos = bhrp.CFrame * CFrame.new(0,0,5)

	TweenService:Create(hrp,TweenInfo.new(0.4),{CFrame=pos}):Play()
end

--// ✅ FIX TOOL REMOTE
local DeadCache = {}

local function fireToolsIfDead(boss)
	if not boss then return end

	local hum = boss:FindFirstChildOfClass("Humanoid")

	local dead = false

	if not hum then dead = true
	elseif hum.Health <= 0 then dead = true
	elseif not boss.Parent then dead = true
	end

	if dead and not DeadCache[boss] then
		DeadCache[boss] = true

		for _,tool in pairs(lp.Backpack:GetChildren()) do
			if tool:IsA("Tool") then
				for _,v in pairs(tool:GetDescendants()) do
					if v:IsA("RemoteEvent") then
						pcall(function()
							v:FireServer()
						end)
					end
				end
			end
		end
	elseif not dead then
		DeadCache[boss] = nil
	end
end

--// LOOP
task.spawn(function()
	while true do
		if getgenv().AutoFarm then

			local bossName, questName = getTarget()
			local boss = findBoss(bossName)

			doQuest(questName)

			if boss then
				tweenBehind(boss)
				fireToolsIfDead(boss)
			end
		end
		task.wait(0.25)
	end
end)

--// UI MAIN TAB
Tab:AddDropdown({
	Name = "Select Sea",
	Options = {"Sea 1","Sea 2"},
	Default = "Sea 1",
	Callback = function(v)
		getgenv().SeaSelect = v
	end
})

Tab:AddToggle({
	Name = "Auto Farm",
	Default = false,
	Callback = function(v)
		getgenv().AutoFarm = v
	end
})

--================ GLOBAL =================
getgenv().SelectedNPC = nil
getgenv().AutoBring = false
getgenv().BringDist = 6

getgenv().AutoHitbox = false
getgenv().HitboxSize = 30

getgenv().OneShot = false
getgenv().AutoOneShot = false

getgenv().SelectedSkill = "Z"
getgenv().AutoSkill = false
getgenv().AutoKill = false

local ShotDelay = 0.4
local LastShot = 0
local HitboxCache = {}

--================ UTILS ==================
local function GetNPC()
    if not getgenv().SelectedNPC then return end
    return workspace["NPC DAMAGE"]:FindFirstChild(getgenv().SelectedNPC)
end

local function GetHRP(model)
    if not model then return end
    return model:FindFirstChild("HumanoidRootPart") or model.PrimaryPart
end

--================ NPC LIST ===============
local NPC_List = {}
pcall(function()
    for _,v in pairs(workspace["NPC DAMAGE"]:GetChildren()) do
        if v:IsA("Model") then
            table.insert(NPC_List, v.Name)
        end
    end
end)

--================ UI MAIN CONT'D =====================
Tab:AddDropdown({
    Name = "Select NPC / Boss",
    Options = NPC_List,
    Callback = function(v)
        getgenv().SelectedNPC = v
    end
})

Tab:AddButton({
    Name = "Teleport To NPC",
    Callback = function()
        local npc = GetNPC()
        local hrp = GetHRP(npc)
        local char = LP.Character
        if hrp and char and char:FindFirstChild("HumanoidRootPart") then
            char.HumanoidRootPart.CFrame = hrp.CFrame * CFrame.new(0,0,-4)
        end
    end
})

Tab:AddSlider({
    Name = "Bring Distance",
    Min = 3, Max = 15, Default = 6,
    Callback = function(v)
        getgenv().BringDist = v
    end
})

Tab:AddToggle({
    Name = "Auto Bring (Front)",
    Callback = function(v)
        getgenv().AutoBring = v
    end
})

Tab:AddSlider({
    Name = "Hitbox Size",
    Min = 10, Max = 80, Default = 30,
    Callback = function(v)
        getgenv().HitboxSize = v
    end
})

Tab:AddToggle({
    Name = "Hitbox Resize",
    Callback = function(v)
        getgenv().AutoHitbox = v
    end
})

local function KillNPC()
    local npc = GetNPC()
    if not npc then return end
    local hum = npc:FindFirstChildOfClass("Humanoid")
    if hum and hum.Health > 0 then
        sethiddenproperty(LP,"SimulationRadius",math.huge)
        sethiddenproperty(LP,"MaxSimulationRadius",math.huge)
        hum.Health = 0
    end
end

Tab:AddButton({
    Name = "One Shot",
    Callback = function()
        KillNPC()
    end
})

Tab:AddToggle({
    Name = "Auto One Shot",
    Callback = function(v)
        getgenv().AutoOneShot = v
    end
})

Tab:AddDropdown({
    Name = "Select Skill",
    Options = {"Z","X","C","V","B","N","F","K"},
    Default = "Z",
    Callback = function(v)
        getgenv().SelectedSkill = v
    end
})

local AutoQuest = false
local SelectedQuest = nil
local QuestTable = {
    ["Okaku"] = function() workspace.NPCS.Quest10.ClickPart.QuestTake.QuestTake.Accept3.RemoteEvent:FireServer() end,
    ["Pride"] = function() workspace.NPCS.Quest9.ClickPart.QuestTake.QuestTake.Accept3.RemoteEvent:FireServer() end,
    ["Grab"] = function() workspace.NPCS.Quest7.ClickPart.QuestTake.QuestTake.Accept2.RemoteEvent:FireServer() end,
    ["Sukuna"] = function() workspace.NPCS.Quest6.ClickPart.QuestTake.QuestTake.Accept1.RemoteEvent:FireServer() end,
    ["Geto"] = function() workspace.NPCS.Quest8.ClickPart.QuestTake.QuestTake.Accept1.RemoteEvent:FireServer() end,
    ["Cid"] = function() workspace.NPCS.Quest8.ClickPart.QuestTake.QuestTake.Accept2.RemoteEvent:FireServer() end
}

Tab:AddDropdown({
    Name = "Chọn Quest",
    Default = "",
    Options = {"Pride", "Grab", "Sukuna", "Geto", "Cid", "Okaku"},
    Callback = function(Value) SelectedQuest = Value end
})

Tab:AddToggle({
    Name = "Auto Quest",
    Default = false,
    Callback = function(Value)
        AutoQuest = Value
        if Value then
            task.spawn(function()
                while AutoQuest do
                    if SelectedQuest and QuestTable[SelectedQuest] then
                        pcall(function() QuestTable[SelectedQuest]() end)
                    end
                    task.wait(0.1)
                end
            end)
        end
    end
})

Tab:AddToggle({
    Name = "Auto Skill When Boss Die",
    Callback = function(v) getgenv().AutoSkill = v end
})

Tab:AddToggle({
    Name = "Auto Kill (Tween + Fire)",
    Callback = function(v) getgenv().AutoKill = v end
})

--================ TELEPORT TAB =================
local function IslandTele(cf)
    if LP.Character and LP.Character:FindFirstChild("HumanoidRootPart") then
        LP.Character.HumanoidRootPart.CFrame = cf
    end
end

TabTele:AddLabel("Sea 1 Islands")
TabTele:AddButton({Name = "đảo khởi đầu", Callback = function() IslandTele(CFrame.new(485.583771, 35.5632935, -511.945404)) end})
TabTele:AddButton({Name = "đảo tuyết", Callback = function() IslandTele(CFrame.new(-915.918945, 33.7605095, 282.443604)) end})
TabTele:AddButton({Name = "đảo cát", Callback = function() IslandTele(CFrame.new(-708.765259, 69.1108398, 1745.13916)) end})
TabTele:AddButton({Name = "đảo trời", Callback = function() IslandTele(CFrame.new(-4594.52393, 4279.44092, 474.423523)) end})
TabTele:AddButton({Name = "thị trấn end", Callback = function() IslandTele(CFrame.new(-2223.75146, 36.3414612, 1965.90369)) end})
TabTele:AddButton({Name = "đảo minh mama", Callback = function() IslandTele(CFrame.new(2569.90283, 51.1074524, -65.4458542)) end})
TabTele:AddButton({Name = "đảo dark", Callback = function() IslandTele(CFrame.new(-3465.68188, 66.2542191, 3718.19531)) end})

TabTele:AddLabel("Sea 2 Islands")
TabTele:AddButton({Name = "đảo kaido", Callback = function() IslandTele(CFrame.new(-685, 87690, 789)) end})
TabTele:AddButton({Name = "đảo platium", Callback = function() IslandTele(CFrame.new(-1258, 87700, 3260)) end})
TabTele:AddButton({Name = "đảo marine", Callback = function() IslandTele(CFrame.new(-160, 87750, -2010)) end})
TabTele:AddButton({Name = "đảo nickbeo", Callback = function() IslandTele(CFrame.new(-1600, 87700, 637)) end})
TabTele:AddButton({Name = "đảo garou", Callback = function() IslandTele(CFrame.new(1600, 87700, 1073)) end})
TabTele:AddButton({Name = "đảo sukuna", Callback = function() IslandTele(CFrame.new(1500, 87700, 2800)) end})
TabTele:AddButton({Name = "đảo grab", Callback = function() IslandTele(CFrame.new(2040, 87700, 50)) end})
TabTele:AddButton({Name = "đảo cid và geto", Callback = function() IslandTele(CFrame.new(1635, 87710, -1085)) end})
TabTele:AddButton({Name = "đảo sun", Callback = function() IslandTele(CFrame.new(1603, 87700, -2191)) end})
TabTele:AddButton({Name = "đảo goly", Callback = function() IslandTele(CFrame.new(-6321.96729, 87714.7656, -2994.5603)) end})

--================ LOGIC PHỤ ===================
local function FireSkill()
    for _,tool in pairs(LP.Backpack:GetChildren()) do
        if tool:IsA("Tool") then
            local s = tool:FindFirstChild(getgenv().SelectedSkill)
            if s and s:FindFirstChild("Fire") then
                pcall(function() s.Fire:FireServer() end)
            end
        end
    end
end

local function FireAllRemote()
    for _,tool in pairs(LP.Backpack:GetChildren()) do
        if tool:IsA("Tool") then
            for _,v in pairs(tool:GetDescendants()) do
                if v:IsA("RemoteEvent") then
                    pcall(function() v:FireServer() task.wait(0.05) end)
                end
            end
        end
    end
end

RunService.Heartbeat:Connect(function()
    local npc = GetNPC()
    local hrp = GetHRP(npc)
    local char = LP.Character
    local hum = npc and npc:FindFirstChildOfClass("Humanoid")
    if not npc or not hrp or not char or not char:FindFirstChild("HumanoidRootPart") then return end

    if getgenv().AutoHitbox then
        if not HitboxCache[hrp] then HitboxCache[hrp] = hrp.Size end
        hrp.Size = Vector3.new(getgenv().HitboxSize,getgenv().HitboxSize,getgenv().HitboxSize)
        hrp.CanCollide = false
    elseif HitboxCache[hrp] then
        hrp.Size = HitboxCache[hrp]
    end

    if getgenv().AutoBring then
        hrp.CFrame = char.HumanoidRootPart.CFrame + char.HumanoidRootPart.CFrame.LookVector * getgenv().BringDist
    end

    if getgenv().AutoOneShot and tick() - LastShot >= ShotDelay then
        LastShot = tick()
        KillNPC()
    end

    if getgenv().AutoSkill and hum and hum.Health <= 0 then FireSkill() end

    if getgenv().AutoKill then
        TweenService:Create(char.HumanoidRootPart, TweenInfo.new(0.25,Enum.EasingStyle.Linear), {CFrame = hrp.CFrame * CFrame.new(0,0,4)}):Play()
        FireAllRemote()
    end
end)

--================ TOGGLE UI BUTTON =================
local ScreenGui = Instance.new("ScreenGui")
ScreenGui.Name = "Toggleui"
ScreenGui.Parent = game.Players.LocalPlayer:WaitForChild("PlayerGui")
ScreenGui.ResetOnSpawn = false

local Toggle = Instance.new("TextButton")
Toggle.Name = "Toggle"
Toggle.Parent = ScreenGui
Toggle.BackgroundColor3 = Color3.fromRGB(0, 0, 0)
Toggle.BackgroundTransparency = 0.5
Toggle.Position = UDim2.new(0, 0, 0.454706937, 0)
Toggle.Size = UDim2.new(0, 50, 0, 50)
Toggle.Draggable = true

local Corner = Instance.new("UICorner")
Corner.CornerRadius = UDim.new(0.2, 0)
Corner.Parent = Toggle

local Image = Instance.new("ImageLabel")
Image.Name = "Icon"
Image.Parent = Toggle
Image.Size = UDim2.new(1, 0, 1, 0)
Image.BackgroundTransparency = 1
Image.Image = "rbxassetid://259226716" 

local Corner2 = Instance.new("UICorner")
Corner2.CornerRadius = UDim.new(0.2, 0)
Corner2.Parent = Image

Toggle.MouseButton1Click:Connect(function()
  OrionLib:ToggleUi()
end)

--================ LOCAL PLAYER TAB =================
local Char = LP.Character or LP.CharacterAdded:Wait()
local HRP = Char:WaitForChild("HumanoidRootPart")

LP.CharacterAdded:Connect(function(c) Char = c HRP = Char:WaitForChild("HumanoidRootPart") end)

local AuraEnabled = false
local AuraSize = 15
local AuraBall

local function CreateAura()
	if AuraBall then AuraBall:Destroy() end
	AuraBall = Instance.new("Part")
	AuraBall.Shape = Enum.PartType.Ball
	AuraBall.Material = Enum.Material.Neon
	AuraBall.Color = Color3.fromRGB(255,0,0)
	AuraBall.Transparency = 0.3
	AuraBall.Anchored = true
	AuraBall.CanCollide = false
	AuraBall.CanTouch = true
	AuraBall.Massless = true
	AuraBall.Size = Vector3.new(AuraSize,AuraSize,AuraSize)
	AuraBall.Parent = workspace

	task.spawn(function()
		while AuraEnabled and AuraBall and HRP do
			AuraBall.CFrame = HRP.CFrame
			task.wait()
		end
	end)

	AuraBall.Touched:Connect(function(hit)
		local model = hit.Parent
		local plr = game.Players:GetPlayerFromCharacter(model)
		if plr and plr ~= LP then
			for _,tool in pairs(LP.Backpack:GetChildren()) do
				if tool:IsA("Tool") then
					for _,r in pairs(tool:GetDescendants()) do
						if r:IsA("RemoteEvent") then pcall(function() r:FireServer() end) end
					end
				end
			end
			local equip = Char:FindFirstChildOfClass("Tool")
			if equip then
				for _,r in pairs(equip:GetDescendants()) do
					if r:IsA("RemoteEvent") then pcall(function() r:FireServer() end) end
				end
			end
		end
	end)
end

Tab2:AddToggle({
	Name = "Auto Skill Aura",
	Default = false,
	Callback = function(Value)
		AuraEnabled = Value
		if AuraEnabled then CreateAura() else if AuraBall then AuraBall:Destroy() AuraBall = nil end end
	end
})

Tab2:AddSlider({
	Name = "Aura Size",
	Min = 10, Max = 120, Default = 15,
	Color = Color3.fromRGB(255,215,0),
	Increment = 1, ValueName = "Studs",
	Callback = function(Value)
		AuraSize = Value
		if AuraBall then AuraBall.Size = Vector3.new(Value,Value,Value) end
	end
})

Tab2:AddLabel("Visuals")

local ESPEnabled, BackpackESPEnabled, TracerEnabled = false, false, false
local ESPSize = 14
local Camera = workspace.CurrentCamera
local ESPFolder = Instance.new("Folder", game.CoreGui)

local function CreateESP(Player)
	if Player == LP then return end
	local Billboard = Instance.new("BillboardGui")
	Billboard.Size = UDim2.new(0,200,0,50)
	Billboard.AlwaysOnTop = true
	Billboard.Parent = ESPFolder
	local Text = Instance.new("TextLabel", Billboard)
	Text.Size = UDim2.new(1,0,1,0)
	Text.BackgroundTransparency = 1
	Text.TextColor3 = Color3.new(1,0,0)
	Text.TextStrokeTransparency = 0
	Text.TextScaled = true
	
	task.spawn(function()
		while ESPEnabled and Player.Parent do
			local Char = Player.Character
			if Char and Char:FindFirstChild("Head") then
				Billboard.Adornee = Char.Head
				local level = "?"
				pcall(function() level = Player.Data.Level.Value end)
				local hp = Char:FindFirstChildOfClass("Humanoid") and math.floor(Char:FindFirstChildOfClass("Humanoid").Health) or "?"
				Text.Text = Player.Name.." | Lv:"..level.." | HP:"..hp
				Text.TextSize = ESPSize
			end
			task.wait(0.2)
		end
		Billboard:Destroy()
	end)
end

Tab2:AddToggle({ Name = "ESP Player", Default = false, Callback = function(v) ESPEnabled = v if v then for _,p in pairs(Players:GetPlayers()) do CreateESP(p) end end end })
Tab2:AddToggle({ Name = "Tracers", Default = false, Callback = function(v) TracerEnabled = v end })
Tab2:AddSlider({ Name = "ESP Size", Min = 10, Max = 30, Default = 14, Callback = function(v) ESPSize = v end })

--================ WORLD TAB ===================
local AutoPlay = false
Tab3:AddToggle({
	Name = "Auto Nhấn Play",
	Default = false,
	Callback = function(v)
		AutoPlay = v
		task.spawn(function()
			while AutoPlay do
				pcall(function() for _,v in pairs(game:GetDescendants()) do if v.Name == "Play" and v:IsA("RemoteEvent") then v:FireServer() end end end)
				task.wait(2)
			end
		end)
	end
})

local KillAura = false
local AuraSizeW = 30
local AuraCircle
task.spawn(function()
	while task.wait(2.4) do
		if KillAura and LP.Character:FindFirstChild("HumanoidRootPart") then
			pcall(function() sethiddenproperty(LP,"SimulationRadius",9999999) end)
			for _,mob in pairs(workspace:GetDescendants()) do
				if mob:IsA("Humanoid") and mob.Parent ~= LP.Character and mob.Health > 0 then
					local root = mob.Parent:FindFirstChild("HumanoidRootPart")
					if root and (root.Position - LP.Character.HumanoidRootPart.Position).Magnitude <= AuraSizeW then mob.Health = 0 end
				end
			end
		end
	end
end)

Tab3:AddToggle({ Name = "Kill Aura", Default = false, Callback = function(v) KillAura = v end })
Tab3:AddSlider({ Name = "kích thước Aura", Min = 10, Max = 520, Default = 30, Callback = function(v) AuraSizeW = v end })

getgenv().AutoArmor = false
Tab3:AddToggle({ Name = "Auto Armor ⭐", Default = false, Callback = function(v) getgenv().AutoArmor = v end })

getgenv().InfJump = false
game:GetService("UserInputService").JumpRequest:Connect(function()
	if getgenv().InfJump then LP.Character:FindFirstChildOfClass("Humanoid"):ChangeState(Enum.HumanoidStateType.Jumping) end
end)
Tab3:AddToggle({ Name = "Inf Jump 🦘", Default = false, Callback = function(v) getgenv().InfJump = v end })

getgenv().ItemVacuum = false
task.spawn(function()
	while true do
		if getgenv().ItemVacuum and LP.Character:FindFirstChild("HumanoidRootPart") then
			for _, v in pairs(workspace:GetDescendants()) do if v:IsA("Tool") then v.Handle.CFrame = LP.Character.HumanoidRootPart.CFrame end end
		end
		task.wait(0.5)
	end
end)
Tab3:AddToggle({ Name = "Hút All Item Map 🎒", Default = false, Callback = function(v) getgenv().ItemVacuum = v end })

OrionLib:Init()
