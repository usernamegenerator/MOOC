# Problem Set 3: Simulating the Spread of Disease and Virus Population Dynamics 

import random
import pylab
from ps3b_precompiled_36 import *
''' 
Begin helper code
'''

class NoChildException(Exception):
    """
    NoChildException is raised by the reproduce() method in the SimpleVirus
    and ResistantVirus classes to indicate that a virus particle does not
    reproduce. You can use NoChildException as is, you do not need to
    modify/add any code.
    """

'''
End helper code
'''

#
# PROBLEM 1
#
class SimpleVirus(object):

    """
    Representation of a simple virus (does not model drug effects/resistance).
    """
    def __init__(self, maxBirthProb, clearProb):
        """
        Initialize a SimpleVirus instance, saves all parameters as attributes
        of the instance.        
        maxBirthProb: Maximum reproduction probability (a float between 0-1)        
        clearProb: Maximum clearance probability (a float between 0-1).
        """

        # 
        self.maxBirthProb = maxBirthProb
        self.clearProb = clearProb

    def getMaxBirthProb(self):
        """
        Returns the max birth probability.
        """
        # 
        return self.maxBirthProb

    def getClearProb(self):
        """
        Returns the clear probability.
        """
        # 
        return self.clearProb

    def doesClear(self):
        """ Stochastically determines whether this virus particle is cleared from the
        patient's body at a time step. 
        returns: True with probability self.getClearProb and otherwise returns
        False.
        """
        # 
        #random.seed(0) # WTF, having the same seed break the probabbility
        if(random.random() < self.getClearProb()):
            return True
        else:
            return False

    
    def reproduce(self, popDensity):
        """
        Stochastically determines whether this virus particle reproduces at a
        time step. Called by the update() method in the Patient and
        TreatedPatient classes. The virus particle reproduces with probability
        self.maxBirthProb * (1 - popDensity).
        
        If this virus particle reproduces, then reproduce() creates and returns
        the instance of the offspring SimpleVirus (which has the same
        maxBirthProb and clearProb values as its parent).         

        popDensity: the population density (a float), defined as the current
        virus population divided by the maximum population.         
        
        returns: a new instance of the SimpleVirus class representing the
        offspring of this virus particle. The child should have the same
        maxBirthProb and clearProb values as this virus. Raises a
        NoChildException if this virus particle does not reproduce.               
        """

        # 
        #random.seed(0) # WTF, having the same seed break the probabbility
        probability = self.maxBirthProb * (1 - popDensity)
        if(random.random() < probability):
            return SimpleVirus(self.getMaxBirthProb(),self.clearProb)
        else:
            raise NoChildException


#v1 = SimpleVirus(1.0, 0.0)
#print(v1.doesClear()) # False
#v1 = SimpleVirus(0.0, 0.0)
#print(v1.doesClear()) # False
#v1 = SimpleVirus(1.0, 1.0)
#print(v1.doesClear()) # True
#v1 = SimpleVirus(0.0, 1.0)
#print(v1.doesClear()) # True
#v1 = SimpleVirus(0.96, 0.72)
#print(v1.reproduce(0.04))
            
            
class Patient(object):
    """
    Representation of a simplified patient. The patient does not take any drugs
    and his/her virus populations have no drug resistance.
    """    

    def __init__(self, viruses, maxPop):
        """
        Initialization function, saves the viruses and maxPop parameters as
        attributes.

        viruses: the list representing the virus population (a list of
        SimpleVirus instances)

        maxPop: the maximum virus population for this patient (an integer)
        """

        # 
        self.viruses = viruses
        self.maxPop = maxPop
        # popDensity is defined as the ratio of 
        # the current virus population to the maximum virus population for a patient 
        # and should be calculated in the update method of the Patient class.
        self.popDensity = len(self.viruses) / float(self.maxPop)

    def getViruses(self):
        """
        Returns the viruses in this Patient.
        """
        # 
        # return a copy of the list to prevent it gets modified while looping
        # https://prod-edxapp.edx-cdn.org/assets/courseware/v1/3d1ce5279f58011523cc5ee77698684d/asset-v1:MITx+6.00.2x+3T2018a+type@asset+block/6.002x_style_guide.pdf
        return self.viruses[:]


    def getMaxPop(self):
        """
        Returns the max population.
        """
        # 
        return self.maxPop


    def getTotalPop(self):
        """
        Gets the size of the current total virus population. 
        returns: The total virus population (an integer)
        """

        #         
        return len(self.viruses)


    def update(self):
        """
        Update the state of the virus population in this patient for a single
        time step. update() should execute the following steps in this order:
        
        - Determine whether each virus particle survives and updates the list
        of virus particles accordingly.   
        
        - The current population density is calculated. This population density
          value is used until the next call to update() 
        
        - Based on this value of population density, determine whether each 
          virus particle should reproduce and add offspring virus particles to 
          the list of viruses in this patient.                    

        returns: The total virus population at the end of the update (an
        integer)
        """

        # 
        viruses_list = self.getViruses()
        for v in viruses_list:
            if(v.doesClear()):
                self.viruses.remove(v) # use the copy for iteration, to remove the original
        
        viruses_list = self.getViruses()
        for v in viruses_list:
            if(self.getTotalPop() < self.maxPop):
                try:
                    self.viruses.append(v.reproduce(self.popDensity))
                except NoChildException:
                    pass
        
        return len(self.viruses)

#viruses = [SimpleVirus(0.34, 0.94), SimpleVirus(0.57, 0.77), SimpleVirus(0.51, 0.06), SimpleVirus(0.59, 0.46), SimpleVirus(0.05, 0.2)]
#P1 = Patient(viruses, 7)
#print(P1.getTotalPop())
#virus = SimpleVirus(1.0, 0.0)
#patient = Patient([virus], 100)
#print(patient.update())
#print(patient.update())
#print(patient.update())
#print(patient.update())
#print(patient.update())
#print(patient.update())
#print(patient.update())
#print(patient.update())
#print(patient.getTotalPop())
#virus = SimpleVirus(1.0, 1.0)
#patient = Patient([virus], 100)
#print(patient.getTotalPop())
#viruses = [SimpleVirus(0.46, 0.95), SimpleVirus(0.74, 0.72), SimpleVirus(0.39, 0.72)]
#P1 = Patient(viruses, 9)
#print(P1.getTotalPop())


#
# PROBLEM 2
#
def simulationWithoutDrug(numViruses, maxPop, maxBirthProb, clearProb,
                          numTrials):
    """
    Run the simulation and plot the graph for problem 3 (no drugs are used,
    viruses do not have any drug resistance).    
    For each of numTrials trial, instantiates a patient, runs a simulation
    for 300 timesteps, and plots the average virus population size as a
    function of time.
    
    average virus population size: means at each time step,
    sum up 300 trials simulations' value / 300
    300 is the numTrials

    numViruses: number of SimpleVirus to create for patient (an integer)
    maxPop: maximum virus population for patient (an integer)
    maxBirthProb: Maximum reproduction probability (a float between 0-1)        
    clearProb: Maximum clearance probability (a float between 0-1)
    numTrials: number of simulation runs to execute (an integer)
    """
    timeSteps = 300
    #virusesPopList has #oftimeSteps's elements
    #and each element is a sum of the virus population at the same timestep during the trials
    virusesPopList = [0 for x in range(timeSteps)]
    for trials in range(numTrials):
        
        totalVirusesPopulation = list()
        virusesList = list()
        
        for i in range(numViruses):
            virusesList.append(SimpleVirus(maxBirthProb,clearProb))
            
        p1 = Patient(virusesList,maxPop)
        
        for j in range(timeSteps):
            p1.update()
            totalVirusesPopulation.append(p1.getTotalPop())
            virusesPopList[j] += p1.getTotalPop()
        
    aveVirusesPopList = [0 for x in range(timeSteps)]
    for x in range(timeSteps):
        aveVirusesPopList[x] = virusesPopList[x] / float(numTrials)
    
    
    pylab.plot(aveVirusesPopList ,label = "SimpleVirus")
    pylab.title("SimpleVirus simulation")
    pylab.xlabel("Time Steps")
    pylab.ylabel("Average Virus Population")
    pylab.legend(loc = "best")
    pylab.show()

#simulationWithoutDrug(100, 1000, 0.99, 0.05, 2)
#simulationWithoutDrug(100, 1000, 0.1, 0.99, 2)
#simulationWithoutDrug(100, 1000, 0.99, 0.1, 2) #grow
#simulationWithoutDrug(100, 1000, 0.1, 0.5, 2)
#simulationWithoutDrug(100, 1000, 0.1, 0.05, 8)

#
# PROBLEM 3
#
class ResistantVirus(SimpleVirus):
    """
    Representation of a virus which can have drug resistance.
    """   

    def __init__(self, maxBirthProb, clearProb, resistances, mutProb):
        """
        Initialize a ResistantVirus instance, saves all parameters as attributes
        of the instance.

        maxBirthProb: Maximum reproduction probability (a float between 0-1)       

        clearProb: Maximum clearance probability (a float between 0-1).

        resistances: A dictionary of drug names (strings) mapping to the state
        of this virus particle's resistance (either True or False) to each drug.
        e.g. {'guttagonol':False, 'srinol':False}, means that this virus
        particle is resistant to neither guttagonol nor srinol.

        mutProb: Mutation probability for this virus particle (a float). This is
        the probability of the offspring acquiring or losing resistance to a drug.
        """

        # 
        SimpleVirus.__init__(self,maxBirthProb,clearProb)
        #self.maxBirthProb = maxBirthProb
        #self.clearProb = clearProb
        self.resistances = resistances
        self.mutProb = mutProb


    def getResistances(self):
        """
        Returns the resistances for this virus.
        """
        # 
        return self.resistances.copy()

    def getMutProb(self):
        """
        Returns the mutation probability for this virus.
        """
        # 
        return self.mutProb

    def isResistantTo(self, drug):
        """
        Get the state of this virus particle's resistance to a drug. This method
        is called by getResistPop() in TreatedPatient to determine how many virus
        particles have resistance to a drug.       

        drug: The drug (a string)

        returns: True if this virus instance is resistant to the drug, False
        otherwise.
        """
        
        # 
        if drug in self.resistances:
            return self.resistances[drug]
        return False


    def reproduce(self, popDensity, activeDrugs):
        """
        Stochastically determines whether this virus particle reproduces at a
        time step. Called by the update() method in the TreatedPatient class.

        A virus particle will only reproduce if it is resistant to ALL the drugs
        in the activeDrugs list. For example, if there are 2 drugs in the
        activeDrugs list, and the virus particle is resistant to 1 or no drugs,
        then it will NOT reproduce.

        Hence, if the virus is resistant to all drugs
        in activeDrugs, then the virus reproduces with probability:      

        self.maxBirthProb * (1 - popDensity).                       

        If this virus particle reproduces, then reproduce() creates and returns
        the instance of the offspring ResistantVirus (which has the same
        maxBirthProb and clearProb values as its parent). The offspring virus
        will have the same maxBirthProb, clearProb, and mutProb as the parent.

        For each drug resistance trait of the virus (i.e. each key of
        self.resistances), the offspring has probability 1-mutProb of
        inheriting that resistance trait from the parent, and probability
        mutProb of switching that resistance trait in the offspring.       

        For example, if a virus particle is resistant to guttagonol but not
        srinol, and self.mutProb is 0.1, then there is a 10% chance that
        that the offspring will lose resistance to guttagonol and a 90%
        chance that the offspring will be resistant to guttagonol.
        There is also a 10% chance that the offspring will gain resistance to
        srinol and a 90% chance that the offspring will not be resistant to
        srinol.

        popDensity: the population density (a float), defined as the current
        virus population divided by the maximum population       

        activeDrugs: a list of the drug names acting on this virus particle
        (a list of strings).

        returns: a new instance of the ResistantVirus class representing the
        offspring of this virus particle. The child should have the same
        maxBirthProb and clearProb values as this virus. Raises a
        NoChildException if this virus particle does not reproduce.
        """

        # 
        for drug in activeDrugs:
            if(not self.isResistantTo(drug)):
                # not resistant to all the drugs, so reproduce with probability
                if(random.random() < self.maxBirthProb * (1 - popDensity)):
                    #reproduce success
                    #need to determine the resistances
                    childResistances = self.resistances.copy()
                    for key in childResistances:
                        #mutant, switch the resitance boolean
                        if(random.random() >= 1-self.mutProb):
                            childResistances[key] = not childResistances[key]
                    return ResistantVirus(self.maxBirthProb,self.clearProb,childResistances,self.mutProb)
                else:
                    #did not reproduce
                    raise NoChildException
                

#ResistantVirus(maxBirthProb, clearProb, resistances, mutProb)
#virus = ResistantVirus(0.0, 1.0, {}, 0.0)
#print(virus.doesClear())
#virus = ResistantVirus(0.0, 1.0, {"drug1":True, "drug2":False}, 0.0)
#print(virus.isResistantTo('drug2')) # False
#virus.reproduce(0, [])
#print(virus.isResistantTo('drug2')) # False
#virus = ResistantVirus(1.0, 0.0, {"drug1":True, "drug2":False}, 0.0)
#print(virus.reproduce(0, ["drug2"]))
#print(virus.reproduce(0, ["drug1"]))
#virus = ResistantVirus(1.0, 0.0, {"drug2": False}, 1.0)
#child = virus.reproduce(0, ["drug2"])
#print(child.isResistantTo("drug2"))
#child = virus.reproduce(0, ["drug2"])
#print(child.isResistantTo("drug2"))
#child = virus.reproduce(0, ["drug2"])
#print(child.isResistantTo("drug2"))
#child = virus.reproduce(0, ["drug2"])
#print(child.isResistantTo("drug2"))
#child = virus.reproduce(0, ["drug2"])
#print(child.isResistantTo("drug2"))
#child = virus.reproduce(0, ["drug2"])
#print(child.isResistantTo("drug2"))
#child = virus.reproduce(0, ["drug2"])
#print(child.isResistantTo("drug2"))
#child = virus.reproduce(0, ["drug2"])
#print(child.isResistantTo("drug2"))
#child = virus.reproduce(0, ["drug2"])
#print(child.isResistantTo("drug2"))



class TreatedPatient(Patient):
    """
    Representation of a patient. The patient is able to take drugs and his/her
    virus population can acquire resistance to the drugs he/she takes.
    """

    def __init__(self, viruses, maxPop):
        """
        Initialization function, saves the viruses and maxPop parameters as
        attributes. Also initializes the list of drugs being administered
        (which should initially include no drugs).              

        viruses: The list representing the virus population (a list of
        virus instances)

        maxPop: The  maximum virus population for this patient (an integer)
        """

        # 
        Patient.__init__(self,viruses,maxPop)
        #self.viruses = viruses
        #self.maxPop = maxPop
        self.prescription = list()


    def addPrescription(self, newDrug):
        """
        Administer a drug to this patient. After a prescription is added, the
        drug acts on the virus population for all subsequent time steps. If the
        newDrug is already prescribed to this patient, the method has no effect.

        newDrug: The name of the drug to administer to the patient (a string).

        postcondition: The list of drugs being administered to a patient is updated
        """

        # 
        if newDrug not in self.prescription:
            self.prescription.append(newDrug)


    def getPrescriptions(self):
        """
        Returns the drugs that are being administered to this patient.

        returns: The list of drug names (strings) being administered to this
        patient.
        """

        # 
        return self.prescription.copy()


    def getResistPop(self, drugResist):
        """
        Get the population of virus particles resistant to the drugs listed in
        drugResist.       

        drugResist: Which drug resistances to include in the population (a list
        of strings - e.g. ['guttagonol'] or ['guttagonol', 'srinol'])

        returns: The population of viruses (an integer) with resistances to all
        drugs in the drugResist list.
        """

        # 
        resistPopulation = 0
        for v in self.viruses:
            print(v)
            for drug in drugResist:
                if(v.isResistantTo(drug)):
                    resistPopulation += 1
                    continue
        return resistPopulation


    def update(self):
        """
        Update the state of the virus population in this patient for a single
        time step. update() should execute these actions in order:

        - Determine whether each virus particle survives and update the list of
          virus particles accordingly

        - The current population density is calculated. This population density
          value is used until the next call to update().

        - Based on this value of population density, determine whether each 
          virus particle should reproduce and add offspring virus particles to 
          the list of viruses in this patient.
          The list of drugs being administered should be accounted for in the
          determination of whether each virus particle reproduces.

        returns: The total virus population at the end of the update (an
        integer)
        """

        # 
        viruses_list = self.getViruses()
        for v in viruses_list:
            if(v.doesClear()):
                self.viruses.remove(v) # use the copy for iteration, to remove the original
        
        viruses_list = self.getViruses()
        popDensity = self.getTotalPop() / float(self.maxPop)
        for v in viruses_list:
                try:
                    self.viruses.append(v.reproduce(popDensity,self.prescription))
                except NoChildException:
                    pass
        
        return len(self.viruses)
        
###test case 1
#virus1 = ResistantVirus(1.0, 0.0, {"drug1": True}, 0.0)
#virus2 = ResistantVirus(1.0, 0.0, {"drug2": False}, 0.0)
#viruses = [virus1, virus2]
#tp = TreatedPatient(viruses, 1000)
#print(tp.getPrescriptions())
#tp.addPrescription('A')
#print(len(tp.getPrescriptions()))
#tp.addPrescription('B')
#print(len(tp.getPrescriptions()))
#tp.addPrescription('A')
#print(len(tp.getPrescriptions()))
        
###test case 2
#virus1 = ResistantVirus(1.0, 0.0, {"drug1": True}, 0.0)
#virus2 = ResistantVirus(1.0, 0.0, {"drug2": False}, 0.0)
#patient = TreatedPatient([virus1, virus2], 1000000)
#patient.addPrescription("drug2")
#patient.update()
#patient.update()
#patient.update()
#patient.update()
#patient.update()
        
#
# PROBLEM 4
#
def simulationWithDrug(numViruses, maxPop, maxBirthProb, clearProb, resistances,
                       mutProb, numTrials):
    """
    Runs simulations and plots graphs for problem 5.

    For each of numTrials trials, instantiates a patient, runs a simulation for
    150 timesteps, adds guttagonol, and runs the simulation for an additional
    150 timesteps.  At the end plots the average virus population size
    (for both the total virus population and the guttagonol-resistant virus
    population) as a function of time.

    numViruses: number of ResistantVirus to create for patient (an integer)
    maxPop: maximum virus population for patient (an integer)
    maxBirthProb: Maximum reproduction probability (a float between 0-1)        
    clearProb: maximum clearance probability (a float between 0-1)
    resistances: a dictionary of drugs that each ResistantVirus is resistant to
                 (e.g., {'guttagonol': False})
    mutProb: mutation probability for each ResistantVirus particle
             (a float between 0-1). 
    numTrials: number of simulation runs to execute (an integer)
    
    """

    # 
    timeSteps = 300
    totalVirusesPopulation = [0 for x in range(timeSteps)]
    totalPopulationOfGuttaResistant = [0 for x in range(timeSteps)]

    for trial in range(numTrials):
        virusList = []
        for i in range(numViruses):
            virusList.append(ResistantVirus(maxBirthProb,clearProb,resistances,mutProb))

        print("len" + str(len(virusList)))

        p1 = TreatedPatient(virusList,maxPop)

        for step in range(timeSteps):
            if(step == 150):
                p1.addPrescription('guttagonol')
            p1.update()
            totalVirusesPopulation[step] += p1.getTotalPop()
            #TODO
            #there is a bug here, the virus list increases with update() function
            #but the object of the virus has none type
            totalPopulationOfGuttaResistant[step] += p1.getResistPop(['guttagonol'])

    aveVirusesPopulation = [0 for x in range(timeSteps)]
    avePopulationOfGuttaResistant = [0 for x in range(timeSteps)]
    for step in range(timeSteps):
        aveVirusesPopulation[step] = totalVirusesPopulation / float(numTrials)
        avePopulationOfGuttaResistant[step] = totalPopulationOfGuttaResistant / float(numTrials)

    pylab.plot(aveVirusesPopulation ,label = "aveVirusesPopulation")
    pylab.plot(avePopulationOfGuttaResistant ,label = "avePopulationOfGuttaResistant")
    pylab.title("SimpleVirus simulation")
    pylab.xlabel("Time Steps")
    pylab.ylabel("Average Virus Population")
    pylab.legend(loc = "best")
    pylab.show()

resistances = {'guttagonol': False}
simulationWithDrug(6, 1000, 0.99, 0.05, resistances ,0.5, 2)
#simulationWithDrug(100, 1000, 0.99, 0.05, resistances ,0.5, 2)
#simulationWithDrug(100, 1000, 0.1, 0.99, 2)
#simulationWithDrug(100, 1000, 0.99, 0.1, 2) #grow
#simulationWithDrug(100, 1000, 0.1, 0.5, 2)
#simulationWithDrug(100, 1000, 0.1, 0.05, 8)