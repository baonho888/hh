local DiscordLib =
    loadstring(game:HttpGet "https://raw.githubusercontent.com/bloodball/-back-ups-for-libs/main/discord")()
 
local win = DiscordLib:Window("VNP")
local serv = win:Server("hack riêng VNP 2⭐", "")
local drops = serv:Channel("All")
local dis = nil
local aura = false
drops:Button("kill aura ", function()
getgenv().G = true
getgenv().Creator = 'https://discord.gg/B3HqPPzFYr - HalloweenGaster'
while getgenv().G and getgenv().Creator == 'https://discord.gg/B3HqPPzFYr - HalloweenGaster' do
wait(0.9)
sethiddenproperty(game.Players.LocalPlayer, "SimulationRadius", 112412400000)
sethiddenproperty(game.Players.LocalPlayer, "MaxSimulationRadius", 112412400000)
for i,d in pairs(game.Workspace:GetDescendants()) do
    if d.ClassName == 'Humanoid' and d.Parent.Name ~= game.Players.LocalPlayer.Name then
        d.Health = 0
    end
end
end
end)
drops:Button(
    "Get max level",
    function()
        DiscordLib:Notification("Notification", "Max level!", "Okay!")
    end
)
local drops = serv:Channel("Fast attack⚔️")
drops:Button("cid", function()
while wait() do
local args = {
    [1] = 8,
    [2] = 3
}

game:GetService("Players").LocalPlayer.PlayerGui.Tengen.Skill1b.Z.TextButtonm1.Hitbox:FireServer(unpack(args))
end
end)

drops:Button("Guts", function()
while wait() do
local args = {
    [1] = 8,
    [2] = 3
}

game:GetService("Players").LocalPlayer.PlayerGui.Zabuza.Skill1b.Z.TextButtonm1.Hitbox:FireServer(unpack(args))
end
end)

drops:Button("YoruV2", function()
while wait() do
local args = {
    [1] = 8,
    [2] = 3
}

game:GetService("Players").LocalPlayer.PlayerGui.YoruV2.Skill1b.Z.TextButtonm1.Hitbox:FireServer(unpack(args))
end
end)

drops:Button("yoruv3", function()
while wait() do
local args = {
    [1] = 8,
    [2] = 3
}

game:GetService("Players").LocalPlayer.PlayerGui.YoruV3.Skill1b.Z.TextButtonm1.Hitbox:FireServer(unpack(args))
end
end)

drops:Button("dragon combatv2",function()
while wait()do
local args = {
    [1] = 8,
    [2] = 1
}

game:GetService("Players").LocalPlayer.PlayerGui.Goku.Skill1b.Z.TextButtonm1.Hitbox:FireServer(unpack(args))
end
end)

drops:Button("geto",function()
while wait() do
local args = {
    [1] = 8,
    [2] = 1
}

game:GetService("Players").LocalPlayer.PlayerGui.Tengen.Skill1b.Z.TextButtonm1.Hitbox:FireServer(unpack(args))
end
end)

local drops = serv:Channel("Auto quest")
drops:Button("lưu ý cần nhấn vào npc nhiệm vụ trước!", function()
end)

drops:Button("quest 1", function()
while wait() do
game:GetService("Players").LocalPlayer.PlayerGui.QuestTake.Accept1.RemoteEvent:FireServer()
end
end)

drops:Button("quest 2", function()
while wait() do
game:GetService("Players").LocalPlayer.PlayerGui.QuestTake.Accept2.RemoteEvent:FireServer()
end
end)

drops:Button("quest 3", function()
while wait() do
game:GetService("Players").LocalPlayer.PlayerGui.QuestTake.Accept3.RemoteEvent:FireServer()
end
end)
drops:Dropdown(
    "Pick me!",
    {"pride", "Special", "Cid", "Getou", "Grab"},
    function(pride)while true do
workspace.NPCS.Quest9.ClickPart.QuestTake.QuestTake.Accept3.RemoteEvent:FireServer()
wait(0.1)
end
        print(bool)
    end)

drops:Toggle("auto quest pride từ xa", false, function(t)
    aura = t
dis = tonumber(v)
workspace.NPCS.Quest9.ClickPart.QuestTake.QuestTake.Accept3.RemoteEvent:FireServer()
end)

drops:Toggle("auto quest kaido", false, function(t)
    aura = t
dis = tonumber(v)
end)
drops:Toggle("auto quest paw user+bandits", false, function(t)
    aura = t
dis = tonumber(v)
while true do
workspace.NPCS.Quest1.ClickPart.QuestTake.QuestTake.Accept1.RemoteEvent:FireServer()
wait(0.1)
end
end)
drops:Toggle("vamper dio+boss bandits", false, function(t)
    aura = t
dis = tonumber(v)
while true do
workspace.NPCS.Quest1.ClickPart.QuestTake.QuestTake.Accept2.RemoteEvent:FireServer()
wait(0.1)
end
end)
drops:Toggle("thằng làm ace thành donut snow boss", false, function(t)
    aura = t
dis = tonumber(v)
while true do
workspace.NPCS.Quest2.ClickPart.QuestTake.QuestTake.Accept2.RemoteEvent:FireServer()
wait(0.1)
end
end)
drops:Toggle("auto quest nickbeo+sand boss", false, function(t)
    aura = t
dis = tonumber(v)
while true do
workspace.NPCS.Quest3.ClickPart.QuestTake.QuestTake.Accept2.RemoteEvent:FireServer()
wait(0.1)
end
end)
drops:Toggle("tengen+sky bandits", false, function(t)
    aura = t
dis = tonumber(v)
while true do
workspace.NPCS.Quest4.ClickPart.QuestTake.QuestTake.Accept1.RemoteEvent:FireServer()
wait(0.1)
end
end)
drops:Toggle("Garu+th ở town", false, function(t)
    aura = t
dis = tonumber(v)
while true do
workspace.NPCS.Quest5.ClickPart.QuestTake.QuestTake.Accept1.RemoteEvent:FireServer()
wait(0.1)
end
end)
drops:Toggle("sukuna", false, function(t)
    aura = t
dis = tonumber(v)
while true do
workspace.NPCS.Quest6.ClickPart.QuestTake.QuestTake.Accept1.RemoteEvent:FireServer()
wait(0.1)
end
end)
drops:Toggle("grab+minmam", false, function(t)
    aura = t
dis = tonumber(v)
while true do
workspace.NPCS.Quest7.ClickPart.QuestTake.QuestTake.Accept2.RemoteEvent:FireServer()
wait(0.1)
end
end)
drops:Toggle("Cid+geto", false, function(t)
    aura = t
dis = tonumber(v)
while true do
workspace.NPCS.Quest8.ClickPart.QuestTake.QuestTake.Accept2.RemoteEvent:FireServer()
wait(0.1)
end
end)
drops:Toggle("cid", false, function(t)
    aura = t
dis = tonumber(v)
while true do
workspace.NPCS.Quest8.ClickPart.QuestTake.QuestTake.Accept1.RemoteEvent:FireServer()
wait(0.1)
end
end)
drops:Toggle("pride", false, function(t)
    aura = t
dis = tonumber(v)
while true do
workspace.NPCS.Quest9.ClickPart.QuestTake.QuestTake.Accept3.RemoteEvent:FireServer()
wait(0.1)
end
end)
drops:Toggle("special", false, function(t)
    aura = t
dis = tonumber(v)
while true do
workspace.NPCS.Quest10.ClickPart.QuestTake.QuestTake.Accept1.RemoteEvent:FireServer()
wait(0.1)
end
end)

drops:Toggle("TP to bandit", false, function(t)
    aura = t
dis = tonumber(v)
game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(688.621216, 43.1711998, -563.640564, 1, 0, 0, 0, 1, 0, 0, 0, 1)
end)
drops:Toggle("TP to snow boss", false, function(t)
    aura = t
dis = tonumber(v)
game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(-1119.84644, 116.619881, 369.243225, 1, 0, 0, 0, 1, 0, 0, 0, 1)
end)
drops:Toggle("TP to sand boss", false, function(t)
    aura = t
dis = tonumber(v)
game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(-518.427063, 47.8109169, 1624.42676, 0.074960649, 0, 0.997186482, 0, 1, 0, -0.997186482, 0, 0.074960649)
end)
drops:Toggle("TP to town boss", false, function(t)
    aura = t
dis = tonumber(v)
game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(-2242.24951, 26.3575649, 1949.05542, 0.992134154, -0, -0.125179008, 0, 1, -0, 0.125179008, 0, 0.992134154)
end)
drops:Toggle("minmama .nhẹ nhàn", false, function(t)
    aura = t
dis = tonumber(v)
game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(2567.36182, 60.4346924, -58.110157, 0.893678546, -0, -0.448707759, 0, 1, -0, 0.448707759, 0, 0.893678546)
end)
drops:Toggle("dark bú quake của bố", false, function(t)
    aura = t
dis = tonumber(v) 
game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(-3465.80298, 65.7531509, 3718.08057, 0.744877338, -0, -0.667201459, 0, 1, -0, 0.667201459, 0, 0.744877338)
end)

drops:Toggle("auto armor ⭐", false, function(t)
    aura = t
dis = tonumber(v)
local Players = game:GetService("Players")
local armors = {"Cursed-Armor", "Unique-Armor", "Darkness-Armor", "Thunder-Armor", "Thunder-Armor", "Diamond-Armor", "Golden-Armor", "Epic-Armor", "Iron-Armor", "Wooden-Armor"} -- Danh sách các loại giáp

for _, player in pairs(Players:GetPlayers()) do
    local backpack = player:FindFirstChild("Backpack")
    if backpack then
        for _, armorName in pairs(armors) do
            local armor = backpack:FindFirstChild(armorName)
            if armor and armor:FindFirstChild("K") and armor.K:FindFirstChild("Fire") then
                armor.K.Fire:FireServer()
            end
        end
    end
end
end)

drops:Toggle("lock mobs 🔒", false, function(t)
    aura = t
dis = tonumber(v)
end)
local drops = serv:Channel("auto farm")
drops:Toggle("auto farm kaido", false, function(t)
    aura = t
dis = tonumber(v)
while true do
game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(-154.796982, 87756.6406, 839.888611, 1, 0, 0, 0, 1, 0, 0, 0, 1)
wait(0.1)
end
end)

    local drops = serv:Channel("auto secret ⭐")
drops:Toggle("auto secret x5", false, function(t)
    aura = t
while true do fireclickdetector(game:GetService("Workspace").MAP["STARTER ISLAND [ Lv 1+ ]"]["Secret Random"].RANDOM)
wait(0.001)
end
end)
drops:Dropdown(
    "select ⚪",
    {"secret sea 2", "Sando", "Yorus v3", "random 50k", "random 350k"},
    function(bool)
        print(bool)
    end)

local drops = serv:Channel("Teleport island")
--[[
Name = <string> - The name of the section.
]]
Tab:AddButton({
	Name = "Đảo khởi đầu",
	Callback = function()
game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(485.583771, 35.5632935, -511.945404)

      		print("button pressed")
  	end    
})

--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
Tab:AddButton({
	Name = "Đảo tuyết",
	Callback = function()
game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(-915.918945, 33.7605095, 282.443604)

      		print("button pressed")
  	end    
})

--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
Tab:AddButton({
	Name = "Đảo cát",
	Callback = function()
game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(-708.765259, 69.1108398, 1745.13916)

      		print("button pressed")
  	end    
})

--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
Tab:AddButton({
	Name = "Ä‘áº£o trá»i",
	Callback = function()
game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(-4594.52393, 4279.44092, 474.423523)

      		print("button pressed")
  	end    
})

--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
Tab:AddButton({
	Name = "đảo end",
	Callback = function()
game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(-2223.75146, 36.3414612, 1965.90369)

      		print("button pressed")
  	end    
})

--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
Tab:AddButton({
	Name = "Đảo minh mama",
	Callback = function()
game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(2569.90283, 51.1074524, -65.4458542)

      		print("button pressed")
  	end    
})

--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
Tab:AddButton({
	Name = "Đảo dark",
	Callback = function()
game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(-3465.68188, 66.2542191, 3718.19531)

      		print("button pressed")
  	end    
})
local Section = Tab:AddSection({
	Name = "Sea 2đŸ‘‡"
})

--[[
Name = <string> - The name of the section.
]]
Tab:AddButton({
	Name = "Đảo kaido",
	Callback = function()
game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(-685, 87690, 789)
      		print("button pressed")
  	end    
})

--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
Tab:AddButton({
	Name = "Đảo platium",
	Callback = function()
game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(-1258, 87700, 3260)
      		print("button pressed")
  	end    
})

--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
Tab:AddButton({
	Name = "=Đảo marine",
	Callback = function()
game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(-160, 87750, -2010)
      		print("button pressed")
  	end    
})

--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
Tab:AddButton({
	Name = "=Đảo nickbeo",
	Callback = function()
game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(-1600, 87700, 637)
      		print("button pressed")
  	end    
})

--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
Tab:AddButton({
	Name = "Đảo garou",
	Callback = function()
game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(1600, 87700, 1073)
      		print("button pressed")
  	end    
})

--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
Tab:AddButton({
	Name = "Đảo sukuna",
	Callback = function()
game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(1500, 87700, 2800)
      		print("button pressed")
  	end    
})

--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
Tab:AddButton({
	Name = "Đảo grab",
	Callback = function()
game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(2040, 87700, 50)
      		print("button pressed")
  	end    
})

--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
Tab:AddButton({
	Name = "Đảo cid và  geto",
	Callback = function()
game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(1635, 87710, -1085)
      		print("button pressed")
  	end    
})

--[[
Name = <string> - The name of the button.
Callback = <function> - The function of the button.
]]
Tab:AddButton({
	Name = "Đảo sun",
	Callback = function()
game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(1603, 87700, -2191)
      		print("button pressed")
  	end    
})

local drops = serv:Channel("pvp")
drops:Button("speed", function()
game.Players.LocalPlayer.Character.Humanoid.WalkSpeed = 80
end)


drops:Button("tele đến chỗ an toàn (khi sắp die)", function()
game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(602.925415, 67.1156769, -532.647766, 0.997549474, 0, 0.0699642524, 0, 1, 0, -0.0699642524, 0, 0.997549474)
end)

local drops = serv:Channel("skill")
drops:Button("hoho", function()
loadstring(game:HttpGet('https://raw.githubusercontent.com/acsu123/HOHO_H/main/Loading_UI'))()
end)

drops:Button("skill", function()
end)
drops:Toggle("skill Z gojo", false, function(t)
    aura = t
dis = tonumber(v)
while true do
game:GetService("Players").LocalPlayer.Character.Gojo.Z.Fire:FireServer()
wait(0.1)
end
end)
drops:Toggle("Skill X gojo ", false, function(t)
    aura = t
dis = tonumber(v)
while true do
game:GetService("Players").LocalPlayer.Character.Gojo.X.Fire:FireServer()
wait(0.1)
end
end)
drops:Toggle("skill C gojo + bug black ", false, function(t)
    aura = t
dis = tonumber(v)
while true do
game:GetService("Players").LocalPlayer.Character.Gojo.C.Fire:FireServer()
wait(0.1)
end
end)

drops:Toggle("hitbox all", false, function(t)
    aura = t
dis = tonumber(v)
_G.HeadSize = 50
_G.Disabled = true
 
game:GetService('RunService').RenderStepped:connect(function()
if _G.Disabled then
for i,v in next, game:GetService('Players'):GetPlayers() do
if v.Name ~= game:GetService('Players').LocalPlayer.Name then
pcall(function()
v.Character.HumanoidRootPart.Size = Vector3.new(_G.HeadSize,_G.HeadSize,_G.HeadSize)
v.Character.HumanoidRootPart.Transparency = 0.7
v.Character.HumanoidRootPart.BrickColor = BrickColor.new("Really blue")
v.Character.HumanoidRootPart.Material = "Neon"
v.Character.HumanoidRootPart.CanCollide = false
end)
end
end
end
end)
end)
local drops = serv:Channel("pint")
drops:Toggle("meles +1000", false, function(t)
    aura = t
dis = tonumber(v)
while true do
-- Script generated by SimpleSpy - credits to exx#9394

local args = {
    [1] = "Melee"
}

game:GetService("ReplicatedStorage").StatSystem.Points:FireServer(unpack(args))

wait(0.1)
end
end)
local drops = serv:Channel("Event fast attack xuyên off pvp")
drops:Toggle("giết bao2008c", false, function(t)
game:GetService("Players").Bao2008c.Backpack.Getou.Hitbox:FireServer()
end)
drops:Toggle("giết  vnpw locgaminh.", false, function(t)
while true do
game:GetService("Players").chaugiatanloczx.Backpack.Guts.Hitbox:FireServer()
wait(0.1)
end
end)

local serv = win:Server("VNP 1⭐", "")
local drops = serv:Channel("auto farm")
drops:Button("code spy", function()
loadstring(game:HttpGet("https://github.com/exxtremestuffs/SimpleSpySource/raw/master/SimpleSpy.lua"))()
end)
drops:Toggle("bandit", false, function(t)
    aura = t
dis = tonumber(v)
while true do
game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(668.926636, 43.1711922, -586.575562, 1, 0, 0, 0, 1, 0, 0, 0, 1)
wait(0.5)
end
end)
drops:Toggle("auto quest bandit", false, function(t)
    aura = t
dis = tonumber(v)
while true do
workspace.NPCS.Quest1.ClickPart.QuestTake.QuestTake.Accept1.RemoteEvent:FireServer()
wait(0.1)
end
end)
drops:Toggle("boss bandit", false, function(t)
    aura = t
dis = tonumber(v)
while true do
workspace.NPCS.Quest1.ClickPart.QuestTake.QuestTake.Accept2.RemoteEvent:FireServer()
wait(0.1)
end
end)
drops:Toggle("boss snow", false, function(t)
    aura = t
dis = tonumber(v)

end)
drops:Toggle("auto quest boss snow", false, function(t)
    aura = t
dis = tonumber(v)
while true do
workspace.NPCS.Quest2.ClickPart.QuestTake.QuestTake.Accept2.RemoteEvent:FireServer()
wait(0.1)
end
end)

drops:Toggle("minmama", false, function(t)
    aura = t
dis = tonumber(v)

end)

drops:Toggle("auto quest minmama", false, function(t)
    aura = t
dis = tonumber(v)

end)
drops:Toggle("dark user", false, function(t)
    aura = t
dis = tonumber(v)

end)

drops:Button("admin inf yield", function()
loadstring(game:HttpGet('https://raw.githubusercontent.com/EdgeIY/infiniteyield/master/source'))()
end)

local drops = serv:Channel("coming soon")
local serv = win:Server("Chức năng khác")

drops:Button("sea 2 telepor ⌛", function()
end)
drops:Button("SHOP", function()
end)
drops:Button("Buy sniper 4.1M beli khá đắt vs newbie", function()fireclickdetector(game:GetService("Workspace").MAP["DAK ISLAND [Lv 1350+]"][" "].ClickDetector)
end)
drops:Button("hanon", function()fireclickdetector(game:GetService("Workspace").MAP["END TOWN [Lv550+] "]["ALL BOSS"][" "].ClickDetector)
end)
drops:Button("real triple katana", function()
end)
drops:Button("beli+Localplayer", function()
end)
drops:Button("inf beli box event càng click nhiều càng nhanh", function()
while true do
fireclickdetector(game:GetService("Workspace").MAP["Event Island"].EventBox.ClickDetector)
wait(0.001)
end
end)
drops:Toggle("super ultra inf skill", false, function(t)
    aura = t
dis = tonumber(v)
end)
