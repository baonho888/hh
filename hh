--================ WHITELIST CHECK =================
local player = game.Players.LocalPlayer
local whitelist = {"bao2008c", "kaiserVN_thanh", "LzJaTUDSmXS", "geometrynub", "noobpet570"}
local isWhitelisted = false

for _, name in pairs(whitelist) do
    if player.Name == name then
        isWhitelisted = true
        break
    end
end

if isWhitelisted then
    print("Welcome! Script is loading...")
else
    player:Kick("MUA SCRIPT KO FREE")
    return -- Dừng script ngay lập tức
end

--================ START ORION LIB =================
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
local TabTele = Window:MakeTab({
    Name = "Teleport Island⭐",
    Icon = "rbxassetid://4483345998"
})

--// GLOBAL SETTINGS
getgenv().AutoFarm = false
getgenv().SeaSelect = "Sea 1"

--// SEA 1 & 2 TABLES
local Sea1Table = {
    {1,"Boss","Quest1"}, {50,"SnowBoss","Quest2"}, {100,"Sand","Quest3"},
    {250,"Enel","Quest4"}, {550,"Ace","Quest5"}, {900,"Minmama","Quest6"}, {1350,"Dark","Quest7"}
}
local Sea2Table = {
    {2000,"Paw","Quest1"}, {4000,"Magma Admiral","Quest2"}, {8000,"Nickbeo","Quest3"},
    {16000,"Tango","Quest4"}, {20000,"Garou","Quest5"}, {50000,"Sukuna","Quest6"},
    {100000,"Grab","Quest7"}, {500000,"Pride","Quest9"}
}

--// FUNCTIONS
local function getLevel()
    local d = LP:FindFirstChild("Data")
    return (d and d:FindFirstChild("Levels")) and d.Levels.Value or 1
end

local function getTarget()
    local level = getLevel()
    local tableUse = getgenv().SeaSelect == "Sea 1" and Sea1Table or Sea2Table
    local result = tableUse[1]
    for _,v in ipairs(tableUse) do
        if level >= v[1] then result = v else break end
    end
    return result[2], result[3]
end

local function findBoss(name)
    local folder = workspace:FindFirstChild("NPC DAMAGE")
    if not folder then return end
    for _,npc in pairs(folder:GetChildren()) do
        if string.find(string.lower(npc.Name), string.lower(name)) then return npc end
    end
end

--// AUTO FARM LOOP
task.spawn(function()
    while true do
        if getgenv().AutoFarm then
            local bossName, questName = getTarget()
            local boss = findBoss(bossName)
            -- Quest Logic
            pcall(function()
                local q = workspace.NPCS:FindFirstChild(questName).ClickPart.QuestTake.QuestTake
                if getgenv().SeaSelect == "Sea 2" and q:FindFirstChild("Accept3") then
                    q.Accept3.RemoteEvent:FireServer()
                elseif q:FindFirstChild("Accept1") then
                    q.Accept1.RemoteEvent:FireServer()
                end
            end)
            if boss and LP.Character:FindFirstChild("HumanoidRootPart") then
                TweenService:Create(LP.Character.HumanoidRootPart, TweenInfo.new(0.4), {CFrame = boss.HumanoidRootPart.CFrame * CFrame.new(0,0,5)}):Play()
            end
        end
        task.wait(0.25)
    end
end)

--================ UI ELEMENTS =================

Tab:AddToggle({
    Name = "Auto Farm",
    Default = false,
    Callback = function(v) getgenv().AutoFarm = v end
})

--================ TELEPORT SECTION =================
local function IslandTele(cf)
    if LP.Character and LP.Character:FindFirstChild("HumanoidRootPart") then
        LP.Character.HumanoidRootPart.CFrame = cf
    end
end

TabTele:AddLabel("Sea 1")
TabTele:AddButton({Name = "đảo khởi đầu", Callback = function() IslandTele(CFrame.new(485.58, 35.56, -511.94)) end})
TabTele:AddButton({Name = "đảo tuyết", Callback = function() IslandTele(CFrame.new(-915.91, 33.76, 282.44)) end})
TabTele:AddButton({Name = "đảo cát", Callback = function() IslandTele(CFrame.new(-708.76, 69.11, 1745.13)) end})
TabTele:AddButton({Name = "đảo trời", Callback = function() IslandTele(CFrame.new(-4594.52, 4279.44, 474.42)) end})
TabTele:AddButton({Name = "thị trấn end", Callback = function() IslandTele(CFrame.new(-2223.75, 36.34, 1965.90)) end})

TabTele:AddLabel("Sea 2")
TabTele:AddButton({Name = "đảo kaido", Callback = function() IslandTele(CFrame.new(-685, 87690, 789)) end})
TabTele:AddButton({Name = "đảo sukuna", Callback = function() IslandTele(CFrame.new(1500, 87700, 2800)) end})
TabTele:AddButton({Name = "đảo goly", Callback = function() IslandTele(CFrame.new(-6321.96, 87714.76, -2994.56)) end})

--================ TOGGLE UI BUTTON =================
local ScreenGui = Instance.new("ScreenGui")
ScreenGui.Name = "Toggleui"
ScreenGui.Parent = LP:WaitForChild("PlayerGui")
ScreenGui.ResetOnSpawn = false

local Toggle = Instance.new("TextButton")
Toggle.Name = "Toggle"
Toggle.Parent = ScreenGui
Toggle.BackgroundColor3 = Color3.fromRGB(0, 0, 0)
Toggle.BackgroundTransparency = 0.5
Toggle.Position = UDim2.new(0, 0, 0.45, 0)
Toggle.Size = UDim2.new(0, 50, 0, 50)
Toggle.Draggable = true
Instance.new("UICorner", Toggle).CornerRadius = UDim.new(0.2, 0)

local Image = Instance.new("ImageLabel", Toggle)
Image.Size = UDim2.new(1, 0, 1, 0)
Image.BackgroundTransparency = 1
Image.Image = "rbxassetid://259226716" 

Toggle.MouseButton1Click:Connect(function() OrionLib:ToggleUi() end)

OrionLib:Init()
